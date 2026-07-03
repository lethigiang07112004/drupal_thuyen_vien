<?php
include('db.php');

$keyword = trim($_GET['keyword'] ?? '');

$sql = "
SELECT DISTINCT
    base.entity_id AS id,

    COALESCE(
        REPLACE(fm.uri, 'public://', '/sites/default/files/'),
        '/sites/tuyendung/static/images/no-image.png'
    ) AS hinh_anh,

    COALESCE(dt.name, 'Đang cập nhật') AS dia_diem,

    COALESCE(
        img.field_image_title,
        cd.field_chuc_danh_value,
        'Tin tuyển dụng'
    ) AS tieu_de_anh,

    COALESCE(cd.field_chuc_danh_value, 'Đang cập nhật') AS chuc_danh,

    COALESCE(ml.field_luong_co_ban_value, 'Thoả thuận') AS muc_luong,

    COALESCE(kn.field_kinh_nghiem_value, 'Không yêu cầu') AS kinh_nghiem,

    COALESCE(ct.body_value, '') AS thong_tin_chi_tiet,

    DATE_FORMAT(FROM_UNIXTIME(tg.created), '%d/%m/%Y') AS ngay_tao

FROM (
    SELECT entity_id
    FROM wtt_field_data_field_chuc_danh
    WHERE bundle = 'thong_tin_tuyen_dung'

    UNION

    SELECT entity_id
    FROM wtt_field_data_field_dia_diem
    WHERE bundle = 'thong_tin_tuyen_dung'

    UNION

    SELECT entity_id
    FROM wtt_field_data_field_luong_co_ban
    WHERE bundle = 'thong_tin_tuyen_dung'
) base

LEFT JOIN wtt_field_data_field_dia_diem d
    ON base.entity_id = d.entity_id

LEFT JOIN wtt_taxonomy_term_data dt
    ON d.field_dia_diem_tid = dt.tid

LEFT JOIN wtt_field_data_field_image img
    ON base.entity_id = img.entity_id

LEFT JOIN wtt_file_managed fm
    ON img.field_image_fid = fm.fid

LEFT JOIN wtt_field_data_field_chuc_danh cd
    ON base.entity_id = cd.entity_id

LEFT JOIN wtt_field_data_field_luong_co_ban ml
    ON base.entity_id = ml.entity_id

LEFT JOIN wtt_field_data_field_kinh_nghiem kn
    ON base.entity_id = kn.entity_id

LEFT JOIN wtt_field_revision_body ct
    ON base.entity_id = ct.entity_id

LEFT JOIN wtt_node tg
    ON base.entity_id = tg.nid

WHERE 1 = 1
";

$params = [];

if (!empty($keyword)) {
    $sql .= "
    AND (
        cd.field_chuc_danh_value LIKE :keyword
        OR dt.name LIKE :keyword
        OR ml.field_luong_co_ban_value LIKE :keyword
        OR kn.field_kinh_nghiem_value LIKE :keyword
        OR img.field_image_title LIKE :keyword
        OR ct.body_value LIKE :keyword
    )
    ";

    $params[':keyword'] = '%' . $keyword . '%';
}

$sql .= " ORDER BY tg.created DESC";

try {

    $stmt = $conn->prepare($sql);

    foreach ($params as $key => $value) {
        $stmt->bindValue($key, $value, PDO::PARAM_STR);
    }

    $stmt->execute();

    $results = $stmt->fetchAll(PDO::FETCH_ASSOC);

} catch (PDOException $e) {

    die("Lỗi SQL: " . $e->getMessage());
}

$details_path = '/sites/tuyendung/static/details.php';
?>
<!DOCTYPE html>
<html lang="vi">

<head>
    <meta charset="UTF-8">
    <title>Danh sách việc làm</title>

    <link rel="stylesheet" href="/sites/tuyendung/static/css/style.css">
    
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&display=swap" rel="stylesheet">

    <link rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">
</head>

<body>

    <?php include('header.php') ?>

    <div class="container" id="danh_sach">

        <div class="main">

            <!-- SEARCH -->
            <div class="search-box">

                <form method="GET" action="" class="search-form">

                    <input
                        type="text"
                        name="keyword"
                        class="search-input"
                        placeholder="Tìm kiếm chức danh, địa điểm, mức lương..."
                        value="<?= htmlspecialchars($keyword) ?>">

                    <button type="submit" class="btn btn-primary">
                        <i class="fa-solid fa-magnifying-glass"></i>&nbsp;
                        Tìm kiếm
                    </button>

                    <?php if ($keyword != ''): ?>
                        <a href="?" class="btn btn-light">
                            <i class="fa-solid fa-rotate-left"></i>&nbsp;
                            Xóa lọc
                        </a>
                    <?php endif; ?>

                </form>

            </div>

            <!-- TITLE -->
            <div class="section-title">
                <h3>🔥 Danh Sách Việc Làm</h3>
            </div>

            <!-- JOB LIST -->
            <div class="job-list">

                <?php if (!empty($results)): ?>

                    <?php foreach ($results as $jobs): ?>

                        <div class="job-card">

                            <div class="job-image">
                                <img
                                    src="<?= htmlspecialchars($jobs['hinh_anh']) ?>"
                                    alt="<?= htmlspecialchars($jobs['tieu_de_anh']) ?>">
                            </div>

                            <div class="job-content">

                                <h3 class="job-title">
                                    <a href="<?= $details_path ?>?id=<?= $jobs['id'] ?>">
                                        <i class="fa-solid fa-anchor"></i>
                                        <?= htmlspecialchars($jobs['tieu_de_anh']) ?>
                                    </a>
                                </h3>

                                <p class="job-info">
                                    <i class="fa-solid fa-location-dot"></i>
                                    <strong>Địa điểm:</strong>
                                    <?= htmlspecialchars($jobs['dia_diem']) ?>
                                </p>

                                <p class="job-info">
                                    <i class="fa-solid fa-money-bill-wave"></i>
                                    <strong>Mức lương:</strong>
                                    <?= htmlspecialchars($jobs['muc_luong']) ?>
                                </p>

                                <p class="job-info">
                                    <i class="fa-solid fa-briefcase"></i>
                                    <strong>Kinh nghiệm:</strong>
                                    <?= htmlspecialchars($jobs['kinh_nghiem']) ?>
                                </p>

                                <p class="job-info">
                                    <i class="fa-solid fa-calendar"></i>
                                    <strong>Ngày đăng:</strong>
                                    <?= htmlspecialchars($jobs['ngay_tao']) ?>
                                </p>
                                <a href="<?= $details_path ?>?id=<?= $jobs['id'] ?>#chi_tiet" class="">
                                    Chi tiết công việc
                                </a>

                            </div>

                        </div>

                    <?php endforeach; ?>

                <?php else: ?>

                    <div class="empty-job">
                        <i class="fa-regular fa-face-frown" style="font-size:40px;margin-bottom:10px;"></i>
                        <p>Không tìm thấy công việc phù hợp.</p>
                    </div>

                <?php endif; ?>

            </div>

        </div>

    </div>

</body>

</html>
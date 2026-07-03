<?php
include('db.php');
//$details_path = './details.php';
$details_path = './details.php';
/* =========================
   1. GET ID JOB
========================= */
$id = isset($_GET['id']) ? (int)$_GET['id'] : 0;

/* =========================
   2. QUERY DETAIL
========================= */
$sql_detail = "
SELECT 
    n.nid AS id,
    n.title,
    COALESCE(REPLACE(fm.uri, 'public://', '/sites/default/files/'), '/no-image.png') AS hinh_anh,
    COALESCE(dt.name, 'Chưa cập nhật') AS dia_diem,
    COALESCE(cd.field_chuc_danh_value, 'Chưa cập nhật') AS chuc_danh, 
    COALESCE(ml.field_luong_co_ban_value, 'Thỏa thuận') AS muc_luong, 
    COALESCE(kn.field_kinh_nghiem_value, 'Không yêu cầu') AS kinh_nghiem,
    ct.body_value AS thong_tin_chi_tiet,
    DATE_FORMAT(FROM_UNIXTIME(n.created), '%d/%m/%Y') AS ngay_tao
FROM wtt_node n
LEFT JOIN wtt_field_data_field_dia_diem d ON n.nid = d.entity_id
LEFT JOIN wtt_taxonomy_term_data dt ON d.field_dia_diem_tid = dt.tid
LEFT JOIN wtt_field_data_field_image img ON n.nid = img.entity_id
LEFT JOIN wtt_file_managed fm ON fm.fid = img.field_image_fid
LEFT JOIN wtt_field_data_field_chuc_danh cd ON n.nid = cd.entity_id
LEFT JOIN wtt_field_data_field_luong_co_ban ml ON n.nid = ml.entity_id
LEFT JOIN wtt_field_data_field_kinh_nghiem kn ON n.nid = kn.entity_id
LEFT JOIN wtt_field_data_body ct ON n.nid = ct.entity_id
WHERE n.type='thong_tin_tuyen_dung' AND n.nid = :id
LIMIT 10
";

$stmt = $conn->prepare($sql_detail);
$stmt->execute(['id' => $id]);
$job = $stmt->fetch(PDO::FETCH_ASSOC);

if (!$job) {
    die("Không tìm thấy tin tuyển dụng");
}

/* =========================
   3. QUERY LIST JOB
========================= */
$sql_list = "
SELECT 
    n.nid AS id,
    n.title,
    COALESCE(REPLACE(fm.uri, 'public://', '/sites/default/files/'), '/no-image.png') AS hinh_anh,
    COALESCE(dt.name, 'Chưa cập nhật') AS dia_diem
FROM wtt_node n
LEFT JOIN wtt_field_data_field_dia_diem d ON n.nid = d.entity_id
LEFT JOIN wtt_taxonomy_term_data dt ON d.field_dia_diem_tid = dt.tid
LEFT JOIN wtt_field_data_field_image img ON n.nid = img.entity_id
LEFT JOIN wtt_file_managed fm ON fm.fid = img.field_image_fid
WHERE n.type='thong_tin_tuyen_dung'
ORDER BY n.created DESC
LIMIT 5
";

$results = $conn->query($sql_list)->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="vi">

<head>
    <meta charset="UTF-8">
    <title><?= htmlspecialchars($job['title']) ?></title>
    <link rel="stylesheet" href="/sites/tuyendung/static/css/style.css">
    <script src="/sites/tuyendung/static/js/apply.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700&display=swap" rel="stylesheet">
</head>

<body>
    <?php include('header.php') ?>

    <div class="container"  id="chi_tiet">

        <!-- ================= MAIN ================= -->
        <div class="main">

            <div class="card">
                <div class="job-header">
                    <img src="<?= $job['hinh_anh'] ?>">
                    <div>
                        <div class="job-title"><?= htmlspecialchars($job['title']) ?></div>
                        <p>📅 Ngày đăng: <?= $job['ngay_tao'] ?></p>
                    </div>
                </div>

                <div class="info">
                    <div>📍 Địa điểm: <?= $job['dia_diem'] ?></div>
                    <div>💼 Chức danh: <?= $job['chuc_danh'] ?></div>
                    <div>💰 Mức lương: <?= $job['muc_luong'] ?></div>
                    <div>📊 Kinh nghiệm: <?= $job['kinh_nghiem'] ?></div>
                </div>
            </div>

            <div class="card">
                <h3>📄 Thông tin chi tiết</h3>
                <div><?= $job['thong_tin_chi_tiet'] ?></div>
            </div>

            <div class="card">
                <h3 style="display: flex; align-items: center;">
                    <img src="./css/phone.png" style="width: 25px;">
                    Liên hệ
                </h3>

                <div class="actions" style="margin-top: 0;">
                        
                        <a href="/.#apply_nhanh" class="btn btn-primary" style="text-decoration: none;">Apply now</a>
                        <button type="button" class="btn btn-blue" onclick="window.open('https://zalo.me/0904162189')" style="font-size: 16px;font-family: 'Inter', Arial, sans-serif;">Chat Zalo</button>
                </div>
                
            </div>


        </div>

        <!-- ================= SIDEBAR ================= -->
        <div class="sidebar">
            <?php include('list_cv.php') ?>
        </div>

    </div>

    <script>
        function applyJob(id) {
            let phone = document.getElementById("phone").value;

            fetch("apply.php", {
                    method: "POST",
                    headers: {
                        "Content-Type": "application/json"
                    },
                    body: JSON.stringify({
                        phone: phone,
                        job_id: id
                    })
                })
                .then(r => r.json())
                .then(d => {
                    if (d.status === "success") {
                        alert("Apply thành công!");
                    } else {
                        alert("Lỗi!");
                    }
                });
        }
    </script>

</body>

</html>
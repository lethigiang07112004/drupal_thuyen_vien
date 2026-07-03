<?php
include('db.php');
$sql = "
SELECT 
    base.entity_id AS id,
    COALESCE(
        REPLACE(fm.uri, 'public://', '/sites/default/files/'),
        'Không có ảnh'
    ) AS hinh_anh,
    COALESCE(dt.name, ' ') AS dia_diem,
    COALESCE(img.field_image_title, 'Không có tiêu đề') AS tieu_de_anh,
    COALESCE(cd.field_chuc_danh_value, ' ') AS chuc_danh, 
    COALESCE(ml.field_luong_co_ban_value, ' ') AS muc_luong, 
    COALESCE(kn.field_kinh_nghiem_value, ' ') AS kinh_nghiem,
    ct.body_value AS thong_tin_chi_tiet,
   DATE_FORMAT(FROM_UNIXTIME(tg.created), '%d/%m/%Y') AS ngay_tao
FROM (
    SELECT entity_id FROM wtt_field_data_field_chuc_danh WHERE bundle = 'thong_tin_tuyen_dung'
    UNION
    SELECT entity_id FROM wtt_field_data_field_dia_diem WHERE bundle = 'thong_tin_tuyen_dung'
    UNION
    SELECT entity_id FROM wtt_field_data_field_luong_co_ban WHERE bundle = 'thong_tin_tuyen_dung'
) base
LEFT JOIN wtt_field_data_field_dia_diem d ON base.entity_id = d.entity_id
LEFT JOIN wtt_taxonomy_term_data dt ON d.field_dia_diem_tid = dt.tid
LEFT JOIN wtt_field_data_field_image img ON base.entity_id = img.entity_id
LEFT JOIN wtt_file_managed fm ON fm.fid = img.field_image_fid
LEFT JOIN wtt_field_data_field_chuc_danh cd ON base.entity_id = cd.entity_id
LEFT JOIN wtt_field_data_field_luong_co_ban ml ON base.entity_id = ml.entity_id
LEFT JOIN wtt_field_data_field_kinh_nghiem kn ON base.entity_id = kn.entity_id
LEFT JOIN wtt_field_revision_body ct ON base.entity_id = ct.entity_id
LEFT JOIN wtt_node tg ON base.entity_id = tg.nid
ORDER BY base.entity_id DESC";

try {
    $stmt = $conn->query($sql);
    $results = $stmt->fetchAll();
} catch (PDOException $e) {
    die("Lỗi SQL: " . $e->getMessage());
}
//$details_path = $details_path ?? './details.php';
$details_path = '/sites/tuyendung/static/details.php';
?>

<div class="card">

    <div>
        <div class="button" style="border-bottom: 1px solid rgb(238, 238, 238)">
            <h3>🔥 Danh Sách Việc Làm Mới Nhất</h3>
        </div>
        <div id="jobList">
            <?php if (!empty($results)): ?>
                <?php foreach ($results as $jobs): ?>
                        <div class="job" style="border-bottom:1px solid #eee; padding-bottom:15px; margin-bottom:15px;display:flex;gap:15px">
                            <div style="display: flex;align-items: center;">
                                <img src="<?= htmlspecialchars($jobs['hinh_anh']) ?>" width="120">
                            </div>
                            <div>
                                <h3 style="margin: 0;font-size:16px"><i class="fa-solid fa-anchor"></i>
                                    <a href="<?= $details_path ?>?id=<?= $jobs['id'] ?>#chi_tiet"><?= htmlspecialchars($jobs['tieu_de_anh']) ?></a>
                                </h3>
                                <p style="margin: 0;font-size:14px"><strong>Địa điểm: </strong> <?= htmlspecialchars($jobs['dia_diem']) ?>
                                </p>
                               
                                <p style="margin: 0;font-size:14px">
                                    <strong>Mức lương: </strong><?= htmlspecialchars($jobs['muc_luong']) ?>
                                </p>
                                <p style="margin: 0;font-size:14px"><strong>Kinh nghiệm: </strong> <?= htmlspecialchars($jobs['kinh_nghiem']) ?></p>
                                
                            </div>
                        </div>
                    
                <?php endforeach; ?>
            <?php else: ?>
                <p>Hiện tại chưa có tin tuyển dụng nào.</p>
            <?php endif; ?>
        </div>
        
    </div>
</div>

<script>
(function () {

    let expanded = false; // mặc định thu gọn
    const LIMIT = 4;

    function getJobs() {
        return document.querySelectorAll("#jobList .job");
    }

    function hideExtraJobs() {
        const jobs = getJobs();

        jobs.forEach((job, index) => {
            if (index >= LIMIT) {
                job.style.display = "none";
            } else {
                job.style.display = "flex";
            }
        });
    }

    function showAllJobs() {
        const jobs = getJobs();
        jobs.forEach(job => job.style.display = "flex");
    }

    function updateButton() {
        const btn = document.getElementById("btnShow");
        if (!btn) return;

        btn.innerText = expanded ? "Thu gọn" : "Xem tất cả việc làm";
    }

    window.toggleJobs = function () {
        if (!expanded) {
            // 👉 mở rộng
            showAllJobs();
            expanded = true;
        } else {
            // 👉 thu gọn
            hideExtraJobs();
            expanded = false;

            const section = document.getElementById("job-section");
            if (section) {
                section.scrollIntoView({
                    behavior: "smooth"
                });
            }
        }

        updateButton();
    };

    document.addEventListener("DOMContentLoaded", function () {
        hideExtraJobs(); 
        updateButton();
    });

})();
</script>
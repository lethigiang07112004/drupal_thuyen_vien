<?php
$base_url = '/sites/tuyendung/static';
?>

<div class="form-header" style=" font-family: 'Inter', sans-serif;
    background:
        linear-gradient(rgba(5, 25, 55, 0.3),
            rgba(5, 25, 55, 0.35)),
        url('https://images.unsplash.com/photo-1507525428034-b723cf961d3e?q=80&w=2070&auto=format&fit=crop');
    background-size: cover;
    background-position: center;
    
    padding: 30px;
    display: flex;
    align-items: center;
    justify-content: center;">

    <div class="card-1">

        <!-- header-1 -->
        <div class="header-1">

            <div class="logo-1">
                <a href="<?= $base_url ?>/pcf_index.php">
                    PACIFIC MANPOWER
                </a>
            </div>

            <div class="nav">

                <a href="<?= $base_url ?>/ds_cv.php#danh_sach">
                    Việc làm
                </a>

                <a href="<?= $base_url ?>/pcf_index.php#apply_nhanh">
                    Apply
                </a>

            </div>

        </div>

        <!-- hero-1 -->
        <div class="hero-1">

            <h2>
                Tuyển dụng thuyền viên quốc tế
            </h2>

            <p>
                Nhanh – Minh bạch – Thu nhập tốt.
                Cơ hội làm việc trên các tàu quốc tế với mức lương hấp dẫn và quy trình hỗ trợ chuyên nghiệp.
            </p>

            <div class="actions">

                <a href="<?= $base_url ?>/ds_cv.php#danh_sach"
                    class="btn btn-light">
                    <i class="fa-solid fa-briefcase"></i>
                    &nbsp;
                    Xem việc làm
                </a>

                <a href="<?= $base_url ?>/pcf_index.php#apply_nhanh"
                    class="btn btn-primary">
                    ⚡ Apply nhanh
                </a>

            </div>

        </div>

        <!-- NOTICE -->
        <div class="notice">
            <i class="fa-brands fa-whatsapp"></i>
            Ưu tiên xử lý qua Zalo – phản hồi trong 5-10 phút
        </div>

    </div>

</div>
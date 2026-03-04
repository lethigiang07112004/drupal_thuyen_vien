
<?php $arr= explode('{{}}',$rows[0]);?>
<?php
$title=trim(strip_tags($arr[0]));
$body = trim($arr[1]);
$image = trim(strip_tags($arr[2]));
$khuvucdieuhuong = trim(strip_tags($arr[3]));
$kieutau = trim(strip_tags($arr[4]));
$loaitau = trim(strip_tags($arr[5]));
$path = trim(strip_tags($arr[6]));
$created = trim(strip_tags($arr[7]));
$tags = trim(strip_tags($arr[8]));
?>

<?php

$body =trim($arr[1]); ?>
<div class="tasks-list-container compact-list">
    <div class="task-listing">
        <div class="task-listing-details pr-20">
            <img class="img-fluid w-100" src="<?= $image?>" alt="<?=$title?>">
        </div>
    </div>
</div>
<div class="utf-single-page-section-aera mb-30">
    <div class="utf-boxed-list-headline-item">
        <h3><i class="fa mr-1 fa-info"></i> THÔNG SỐ CỦA TÀU <?=$title?></h3>
    </div>
    <div class="task-tags">
        <div class="tasks-list-container compact-list pt-20 pb-20 pl-20 pr-20">
            <div class="utf-single-page-section-aera mb-0">
                <div class="utf-manage-resume-item mt-0">
                    <div class="row">
                        <div class="col-12">
                            <span class="utf-manage-resume-detail-item"><strong> <i class="fa mr-1 fa-ship"></i>Kiểu tàu: </strong> <?=$kieutau?></span>
                            <span class="utf-manage-resume-detail-item"><strong> <i class="fa-brands mr-1 fa-react"></i>Loại khối tàu: </strong> <?=$loaitau?></span>
                            <span class="utf-manage-resume-detail-item"><strong><i class="fa mr-1 fa-earth-americas"></i>Khu vực điều hướng:</strong> <?=$khuvucdieuhuong?></span>

                        </div>

                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<div class="utf-single-page-section-aera ">
    <div class="utf-boxed-list-headline-item">
        <h3><i class="icon-material-outline-file-copy"></i> THÔNG TIN CHI TIẾT</h3>
    </div>
    <div class="task-tags">
        <div class="tasks-list-container compact-list pt-20 pb-20 pl-20 pr-20">
            <div class="utf-single-page-section-aera mb-0">
                <?=$body?>
            </div>
        </div>
    </div>
</div>
<div class="tags">
    <strong><i class="fa mr-1 fa-magnifying-glass"></i>Từ khóa: </strong><span class="mr-2"><?= $tags?></span>
</div>

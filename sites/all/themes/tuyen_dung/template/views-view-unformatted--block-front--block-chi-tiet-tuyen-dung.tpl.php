<?php $ex=explode('{{}}',$rows[0]); ?>
<?php
$title=$ex[0];
$path=$ex[1];
$luong=$ex[2];
$image=$ex[3];
$chucdanh=$ex[4];
$noidung=$ex[5];
$kinhnghiem=$ex[6];
$diadiem=$ex[7];
$vietluc = $ex[8];

?>
<div class="tasks-list-container compact-list">
  <div class="task-listing">
    <div class="task-listing-details pr-20">
      <div class="row">
        <div class="col-md-5">
          <?=$image?>
        </div>
        <div class="col-md-7">
          <div class="task-listing-description">
            <h3 class="task-listing-title"><?=$title?></h3>
            <ul class="task-icons">
              <li><span><i class="fa mr-1 fa-calendar-days"></i> <?=t('Ngày đăng: ')?><?=$vietluc?></span></li>
            </ul>
            <?=$summary?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="utf-single-page-section-aera mb-30">
    <div class="utf-boxed-list-headline-item">
        <h3><i class="icon-feather-briefcase"></i> THÔNG SỐ CỦA <?=$title?></h3>
    </div>
    <div class="task-tags">
        <div class="tasks-list-container compact-list pt-20 pb-20 pl-20 pr-20">
            <div class="utf-single-page-section-aera mb-0">
                <div class="utf-manage-resume-item mt-0">
                    <div class="row">
                        <div class="col-md-6">
                            <span class="utf-manage-resume-detail-item"><strong>Địa điểm:</strong> <?=$diadiem?></span>
                            <span class="utf-manage-resume-detail-item"><strong>Chức danh</strong> <?=$chucdanh?></span>

                        </div>
                        <div class="col-md-6">
                            <span class="utf-manage-resume-detail-item"><strong>Mức lương:</strong> <?=$luong?></span>
                            <span class="utf-manage-resume-detail-item"><strong>Kinh nghiệm:</strong> <?=$kinhnghiem?></span>

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
        <?=$noidung?>
      </div>
    </div>
  </div>
</div>



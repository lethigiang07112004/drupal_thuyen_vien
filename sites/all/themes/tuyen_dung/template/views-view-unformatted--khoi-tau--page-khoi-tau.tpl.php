<div class="news-front">
    <div class="container">
        <div class="row">
            <?php foreach ($rows as $id => $row): ?>
                <?php
                $arr= explode('{{}}',$row);
                $title=trim(strip_tags($arr[0]));
                $body =trim(strip_tags($arr[1]));
                $image = trim(strip_tags($arr[2]));
                $khuvucdieuhuong = trim(strip_tags($arr[3]));
                $kieutau = trim(strip_tags($arr[4]));
                $loaitau = trim(strip_tags($arr[5]));
                $path = trim(strip_tags($arr[6]));
                $created = trim(strip_tags($arr[7]));
                ?>
                <div class="col-xl-4 col-md-4 col-12 position-relative ">
                    <div class="post-block">
                        <div class="post-content">
                            <div class="post-image"><a href="<?=$path?>" title="<?=$title?>"><img src="<?= $image?>" alt="<?=$title?>" class="img-fluid"></a></div>
                            <div class="post-info border px-2">
                                <div class="post-title bg-white py-2">
                                    <h3><a href="<?=$path?>" title="<?=$title?>"><?=$title?></a></h3>
                                </div>
                                <div class="post-info">
                                   <p class="mb-0"><strong class="mr-1">Kiểu tàu: </strong> <?=$kieutau?></p>
                                    <p class="mb-0"><strong class="mr-1">Loại tàu: </strong> <?=$loaitau?></p>
                                    <p><strong class="mr-1">Khu vực điều hướng:</strong> <?=$khuvucdieuhuong?></p>
                                </div>
                                <div class="post-date">

                                   <a href="<?=$path?>" title="Xem chi tết" class="p-2 rounded">Xem chi tiết</a>
                                </div>
                            </div>
                            <div class="post-category d-none">
                                <span class="text-white"><i class="fa-brands mr-1 fa-react"></i><?=$loaitau?></span>
                            </div>

                        </div>

                    </div>
                </div>
            <?php endforeach;?>
        </div>
    </div>
</div>

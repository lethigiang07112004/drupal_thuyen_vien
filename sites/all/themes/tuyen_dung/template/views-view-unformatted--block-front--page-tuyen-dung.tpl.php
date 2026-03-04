
    <div class="container">
        <div class="row">
            <?php foreach ($rows as $id => $row): ?>
                <?php
                $arr = explode('{{}}' , $row);
                $title= trim(strip_tags($arr[0]));
                $image = trim(strip_tags($arr[1]));
                $path = trim(strip_tags($arr[2]));
                $dia_diem = trim(strip_tags($arr[3]));
                $chuc_danh = trim(strip_tags($arr[4]));
                $kinh_nghiem = trim(strip_tags($arr[5]));
                $muc_luong = trim(strip_tags($arr[6]));
                ?>
                <div class="col-xl-4 col-md-4 col-12 mb-4">
                    <div class="post-block border pb-3">
                        <div class="post-image p-3">
                            <a href="<?=$path?>" title="<?=$title?>"><img src="<?= $image?>" alt="<?=$title?>" class="img-fluid w-100"></a>
                        </div>
                        <div class="post-title p-3">
                            <h3><a href="<?=$path?>" title="<?=$title?>"><?=$title?></a></h3>
                        </div>
                        <div class="post-info mb-2">
                            <p class="border-bottom py-1 px-2 bg-light mb-0"><i class="fa fa-map-marker-alt mr-1"></i><strong>Địa điểm: </strong><?=$dia_diem?></p>
                            <p class="border-bottom py-1 px-2 bg-light mb-0"><i class="fab fa-react mr-1"></i><strong>Chức danh: </strong><?=$chuc_danh?></p>
                            <p class="border-bottom py-1 px-2 bg-light mb-0"><i class="fa fa-dollar-sign mr-1"></i><strong>Mức lương: </strong><span class="text-danger"><?=$muc_luong?></span></p>
                            <p class="border-bottom py-1 px-2 bg-light mb-0"><i class="fa fa-star mr-1"></i><strong>Kinh nghiệm: </strong><?=$kinh_nghiem?></p>
                        </div>
                        <div class="btn-ungtuyen px-3">
                            <a href="/lien-he" class="text-white py-xl-2 px-xl-3 p-2 float-right" title="Ứng tuyển ngay">Ứng tuyển ngay</a>
                        </div>
                    </div>
                </div>
            <?endforeach;?>
        </div>

    </div>

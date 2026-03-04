<div class="service">
    <div class="container">
        <h2 class="title"><?=$view->get_title();?></h2>
        <div class="row">
            <?php foreach ($rows as $id => $row): ?>
            <?php
            $arr = explode('{{}}' , $row);
            $title= trim(strip_tags($arr[0]));
            $image = trim(strip_tags($arr[1]));
            $path = trim(strip_tags($arr[2]));
            ?>
            <div class="col-xl-4 col-md-4 col-12  ">
                <div class="post-block">
                    <div class="post-image"><a href="<?=$path?>" title="<?=$title?>"><img src="<?= $image?>" alt="<?=$title?>" class="img-fluid w-100"></a></div>
                    <div class="post-title text-center bg-white py-2">
                        <h3><a href="<?=$path?>" title="<?=$title?>"><?=$title?></a></h3>
                    </div>
                </div>

            </div>
            <?php endforeach;?>
        </div>
    </div>
</div>

<?php foreach ($rows as $row):?>
<?php $ex=explode('{{}}',$row);?>
<div class="intro-banner" data-background-image="<?=$ex[1]?>">
  <div class="container">
    <div class="row">
      <div class="col-md-12">
        <?=$ex[0]?>
      </div>
    </div>
    <?=getinfo_slider();?>
  </div>
</div>
<?php endforeach;?>
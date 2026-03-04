<div class="accordion js-accordion">
  <?php foreach ($rows as $id => $row):?>
    <?php $ex=explode('{{}}',$row);?>
    <div class="utf-accordion-item js-accordion-item active">
      <div class="accordion-header js-accordion-header"><?=($id+1)?>. <?=$ex[0]?></div>
      <div class="accordion-body js-accordion-body">
        <div class="utf-accordion-content"><?=$ex[1]?>
          <?=l('<i class="icon-feather-chevrons-right"></i> Xem thêm',$ex[2],array(
            'attributes' => array(
              'class'=>array('link_more'),
              'title' => t('Xem thêm')
            ),
            'html' => true
          ))?>
        </div>
      </div>
    </div>
  <?php endforeach;?>
</div>

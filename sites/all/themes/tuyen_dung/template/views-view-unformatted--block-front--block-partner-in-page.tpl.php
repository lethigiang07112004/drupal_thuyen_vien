<div class="section padding-top-60 padding-bottom-50">
  <div class="container-fluid">
    <div class="row">
      <div class="col-xl-12">
        <div class="utf-section-headline-item centered margin-top-0 margin-bottom-20">
          <h3><?=$view->get_title()?></h3>
          <div class="utf-headline-display-inner-item"><?=t('Pacific Manpower');?></div>
        </div>
      </div>
      <div class="col-md-12 mt-30">
        <div class="utf-blog-carousel-block-customer">
          <?php foreach ($rows as $row): ?>
            <?php $ex = explode('{{}}', $row); ?>
            <?php $ds_new = explode(',', $ex[1]) ?>
            <?php foreach ($ds_new as $row_new): ?>
              <div class="utf-single-counter"><?= $row_new ?></a></div>
            <?php endforeach; ?>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  </div>
</div>

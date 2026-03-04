<div class="section gray padding-top-60 padding-bottom-50">
  <div class="container">
    <div class="row">
      <div class="col-xl-12">
        <div class="utf-section-headline-item centered margin-top-0 margin-bottom-20">
          <h3><?=$view->get_title()?></h3>
          <div class="utf-headline-display-inner-item"><?=t('Pacific Manpower');?></div>
          <p class="utf-slogan-text"><?=t('Tất cả học viên đến với chúng tôi đều có những mong muốn và ước mơ của riêng mình')?></p>
        </div>
      </div>
      <div class="col-md-12">
        <div class="utf-logo-carousel-block">
          <?php foreach ($rows as $row): ?>
            <?php $ex = explode('{{}}', $row); ?>
            <?php $ds_new = explode(',', $ex[1]) ?>
            <?php foreach ($ds_new as $row_new): ?>
              <div class="utf-carousel-logo-item"><a href="<?= $ex[2] ?>" target="_blank" title="<?= $ex[0] ?>"><?= $row_new ?></a></div>
            <?php endforeach; ?>
          <?php endforeach; ?>
        </div>
      </div>
    </div>
  </div>
</div>

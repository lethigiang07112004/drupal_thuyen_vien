<div class="utf-sidebar-widget-item">
  <h3><?=$view->get_title()?></h3>
  <ul class="utf-featured-list">
    <?php foreach ($rows as $row): ?>
      <li class="utf-sidebr-pro-widget">
        <?=$row?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>

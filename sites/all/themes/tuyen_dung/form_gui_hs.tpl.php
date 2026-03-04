<!DOCTYPE html>
<html>

<head>
</head>

<body class="<?php print $classes; ?>">
   <div class="custom-layout">
  <h1>Gửi tin nhắn cho chúng tôi</h1>
  <div class="field-item"><?php print render($form['name']); ?></div>
  <div class="field-item"><?php print render($form['email']); ?></div>
  <div class="field-item"><?php print render($form['message']); ?></div>
  <div class="actions">
    <?php print drupal_render_children($form); ?>
  </div>
</div>

</body>

</html>
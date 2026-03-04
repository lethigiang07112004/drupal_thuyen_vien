<ul class="nav nav-pills">
  <?php foreach ($rows as $id => $row): ?>
    <li class="nav-item">
      <a class="nav-link <?php if($id==0) print 'active'?>" data-toggle="pill" href="#home<?=$id?>"><?=$row;?></a>
    </li>
  <?php endforeach;?>
</ul>
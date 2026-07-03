function submitApply() {

  const data = {
    phone: document.getElementById('phone').value,
    rank: document.getElementById('rank').value,
    vessel: document.getElementById('vessel').value,
    experience: document.getElementById('experience').value,
    availability: document.getElementById('availability').value
  };

  fetch('/apply-submit', {
    method: 'POST',
    headers: {'Content-Type': 'application/json'},
    body: JSON.stringify(data)
  })
  .then(r => r.json())
  .then(res => {
    if(res.status === 'ok') {
      alert('Gửi hồ sơ thành công');
    }
  });
}
const phoneAdmin = "0856360388"; // Thay bằng số Zalo của bạn (người nhận hồ sơ)
function openModal() {
    document.getElementById('modalHoSo').style.display = 'block';
    document.getElementById('overlay').style.display = 'block';
}

function closeModal() {
    document.getElementById('modalHoSo').style.display = 'none';
    document.getElementById('overlay').style.display = 'none';
    document.getElementById('txtPhone').value = ""; // Xóa dữ liệu cũ khi đóng
}

// Đóng modal khi nhấn vào vùng tối bên ngoài
document.getElementById('overlay').addEventListener('click', closeModal);

function submitHoSo() {
    const userPhone = document.getElementById('txtPhone').value;
    
    if (userPhone.length < 10) {
        alert("Vui lòng nhập số điện thoại hợp lệ!");
        return;
    }

    alert("Đang kết nối Zalo với số: " + userPhone);
    const phoneAdmin = "0901234567"; 
    const noiDung = encodeURIComponent("Tôi muốn gửi hồ sơ, SĐT của tôi: " + userPhone);
    
    window.location.href = `https://zalo.me{phoneAdmin}?text=${noiDung}`;
    
    closeModal(); // Đóng modal sau khi chuyển hướng
}

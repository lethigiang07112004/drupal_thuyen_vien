<!DOCTYPE html>
<html lang="vi">

<head>
    <meta charset="UTF-8">
    
    <title>Pacific Manpower</title>
    <link rel="stylesheet" href="/sites/tuyendung/static/css/style.css">
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800&display=swap" rel="stylesheet">

    <link rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css">
 <style>
        .input-error {
            border: 2px solid #ff4d4d !important;
            background-color: #fff5f5;
        }

        .required-label::after {
            content: " *";
            color: red;
        }
    </style>
</head>

<body>
    <?php include('header.php') ?>
    <div class="container">
        <div class="main">
            <div class="card form" id="apply_nhanh">
                <h3>⚡ Apply Trong 30 Giây</h3>

                <div class="label required-label">Họ và tên</div>
                <input class="input" id="ho_ten" placeholder="Nhập họ và tên">

                <div class="label required-label">SĐT (Zalo)</div>
                <input type="text" id="sdt" class="input" placeholder="09xx xxx xxx">

                <div class="label required-label" >Chức danh</div>
                <select id="chuc_danh" class="input">
                    <option value="">-- Chọn chức danh --</option>
                    <option>Captain</option>
                    <option>CO</option>
                    <option>C.E</option>
                    <option>2/O</option>
                    <option>3O</option>
                    <option>2/E</option>
                    <option>AB</option>
                    <option>BSN</option>
                    <option>CARP</option>
                    <option>OSD</option>
                    <option>DCADET</option>
                    <option>3E</option>
                    <option>4E</option>
                    <option>ETO</option>
                    <option>ELECT</option>
                    <option>ELECT</option>
                    <option>OLR</option>
                    <option>WPR</option>
                    <option>ECADET</option>
                    <option>COOK</option>
                    <option>MESS</option>
                    <option>OSE</option>
                    <option>OS</option>
                </select>

                <div class="label required-label">Loại tàu mong muốn</div>
                <select id="loai_tau_mong_muon" class="input">
                    <option value="">-- Chọn loại tàu --</option>
                    <option>Bulk Carrier</option>
                    <option>Tanker</option>
                    <option>Container</option>
                    <option>General Cargo</option>
                    <option>LNG / LPG</option>
                    <option>General Cargo</option>
                    <option>Offshore</option>
                    <option>Pure car carrier</option>
                </select>

                <div class="label required-label">Tàu vừa đi</div>
                <select id="tau_vua_di" class="input">
                    <option value="">-- Chọn tàu vừa đi--</option>
                    <option>Bulk Carrier</option>
                    <option>Tanker</option>
                    <option>Container</option>
                    <option>General Cargo</option>
                    <option>LNG / LPG</option>
                    <option>General Cargo</option>
                    <option>Offshore</option>
                    <option>Pure car carrier</option>
                </select>

                <div class="label required-label">Kinh nghiệm</div>
                <select id="kinh_nghiem" class="input">
                    <option value="">-- Số năm kinh nghiệm --</option>
                    <option value="0 - dưới 1 năm">0 - dưới 1 năm</option>
                    <option value="1 - dưới 3 năm">1 - dưới 3 năm</option>
                    <option value="3 - dưới 5 năm">3 - dưới 5 năm</option>
                    <option value="5 - dưới 10 năm">5 - dưới 10 năm</option>
                    <option value="10+ năm">10+ năm</option>
                </select>
                <div class="label required-label">Trình độ tiếng anh</div>
                <select id="tieng_anh" class="input">
                    <option value="">-- Trình độ tiếng anh --</option>
                    <option value="Tốt">Tốt</option>
                    <option value="Bình thường">Bình thường</option>
                    <option value="Kém">Kém</option>
                </select>
                <div class="label required-label">Sẵn sàng đi tàu</div>
                <select id="thoi_gian_san_sang" class="input">
                    <option value="">-- Thời gian sẵn sàng --</option>
                    <option value="Ngay lập tức">ASAP (ngay lập tức)</option>
                    <option value="1 tuần">1 tuần</option>
                    <option value="2 tuần">2 tuần</option>
                    <option value="1 tháng">1 tháng</option>
                </select>

                <div class="button-group">
                    <button type="button" class="btn" id="btnSubmit" onclick="saveData()">Gửi hồ sơ</button>
                    <button type="button" class="btn" onclick="window.open('https://zalo.me/0904162189')">Chat Zalo</button>
                </div>
            </div>
            <div id="form-message" style="display:none; margin-top: 15px; padding: 10px; border-radius: 4px; text-align: center; font-weight: 500;">

            </div>
        </div>

        <div class="sidebar">
            <?php include('list_cv.php') ?>
        </div>
    </div>

    <script>
        function saveData() {
            const fields = ['ho_ten', 'sdt', 'chuc_danh', 'kinh_nghiem', 'tieng_anh','tau_vua_di', 'thoi_gian_san_sang', 'loai_tau_mong_muon'];
            const data = {};
            const msgBox = document.getElementById('form-message'); // Thẻ thông báo
            let hasError = false;

            // Hàm hiển thị thông báo nhanh
            const showMsg = (text, type) => {
                msgBox.innerText = text;
                msgBox.style.display = 'block';
                msgBox.style.backgroundColor = type == 'success' ? '#d4edda' : '#f8d7da';
                msgBox.style.color = type == 'success' ? '#155724' : '#721c24';
                msgBox.style.border = `1px solid ${type == 'success' ? '#c3e6cb' : '#f5c6cb'}`;
            };

            // 1. Lấy dữ liệu và kiểm tra trống
            fields.forEach(id => {
                const el = document.getElementById(id);
                const val = el.value.trim();
                data[id] = val;

                if ((id == 'ho_ten' || id == 'sdt' || id == 'kinh_nghiem' || id == 'tieng_anh' ||id == 'tau_vua_di' ||
                        id == 'loai_tau_mong_muon' ||id == 'chuc_danh' || id == 'thoi_gian_san_sang') && val == "") {
                    el.classList.add('input-error');
                    hasError = true;
                } else {
                    el.classList.remove('input-error');
                }
            });

            if (hasError) {
                showMsg("Vui lòng điền đầy đủ thông tin.", "error");
                return;
            }

            // 2. Trạng thái gửi
            const btn = document.getElementById('btnSubmit');
            btn.disabled = true;
            showMsg("Đang gửi hồ sơ, vui lòng đợi...", "success");

            // 3. Gửi Fetch
            const params = new URLSearchParams();
            for (let key in data) {
                params.append(key, data[key]);
            }

            fetch('/ajax/save-application', {
                    method: 'POST',
                    body: params,
                    headers: {
                        'Content-Type': 'application/x-www-form-urlencoded'
                    }
                })
                .then(response => response.json())
                .then(res => {
                    if (res.status == 'success') {
                        showMsg("✅ Gửi hồ sơ thành công! Chúng tôi sẽ liên hệ sớm.", "success");
                        fields.forEach(id => document.getElementById(id).value = ""); // Reset form
                    } else {
                        showMsg("❌ Lỗi: " + res.message, "error");
                    }
                })
                .catch(err => {
                    showMsg("❌ Không thể kết nối máy chủ. Vui lòng thử lại.", "error");
                })
                .finally(() => {
                    btn.disabled = false;
                });
        }
    </script>
</body>

</html>
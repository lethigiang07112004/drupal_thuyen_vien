
(function() {
  const initUploadCCCD = () => {
    const containers = document.querySelectorAll('.customer-drop');

    containers.forEach(container => {
      if (container.dataset.initialized === 'true') return;
      container.dataset.initialized = 'true';

      const fileInput = container.querySelector('input[type="file"]');
      if (!fileInput) return;

      const description = document.createElement('div');
      description.className = 'dropzone-desc';
      description.style.cssText = 'padding: 20px; border: 2px dashed #ccc;text-align: center; position: relative; cursor: pointer; min-height: 50px; display: flex; align-items: center; justify-content: center; flex-direction: column;';
      
      description.innerHTML = `
        <div class="instruction-text">
          <span class="file-status" style="color: rgb(255,255,255);">📤 Chọn file...</span> 
          <span class="drag-text-sp" style="color: #9ca3af;">Hoặc kéo, thả file vào đây</span>
          <div class="note-text" style="font-size: 0.9em; color: #9ca3af; margin-top: 5px;">(Lưu ý: kích thước file phải dưới 5MB)</div>
        </div>
        <div class="file-name-display" style="display: none; color: #374151; word-break: break-all;"></div>
      `;

      fileInput.style.cssText = 'position: absolute; top: 0; left: 0; width: 100%; height: 100%; opacity: 0; z-index: 10; cursor: pointer;';
      container.style.position = 'relative';
      container.appendChild(description);

      const instructionText = description.querySelector('.instruction-text');
      const fileNameDisplay = description.querySelector('.file-name-display');

      fileInput.addEventListener('change', function() {
        if (this.files && this.files.length > 0) {
          instructionText.style.display = 'none';
          fileNameDisplay.innerText = '📤 ' + this.files[0].name;
          fileNameDisplay.style.display = 'block';
        } else {
          instructionText.style.display = 'block';
          fileNameDisplay.style.display = 'none';
        }
      });

      fileInput.addEventListener('dragover', () => {
        description.style.backgroundColor = '#f0f8ff';
        description.style.borderColor = '#007bff';
      });

      ['dragleave', 'drop', 'change'].forEach(eventName => {
        fileInput.addEventListener(eventName, () => {
          description.style.backgroundColor = '';
          description.style.borderColor = '#ccc';

        });
      });
    });
  };
  

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initUploadCCCD);
  } else {
    initUploadCCCD();
  }
  
  document.addEventListener('ajaxComplete', function() {
     setTimeout(initUploadCCCD, 200);
  });
})();

(function() {
  const initCustomDatepicker = () => {
    const dateInputs = document.querySelectorAll('.custom-datepicker-input');

    dateInputs.forEach(input => {
      if (input.dataset.datepickerInitialized === 'true') return;
      input.dataset.datepickerInitialized = 'true'; 

      // --- KHÓA NHẬP LIỆU ---
      input.readOnly = true; 
      input.style.cursor = 'default'; 

      // 1. Tạo container bọc ngoài
      const wrapper = document.createElement('div');
      wrapper.className = 'datepicker-wrapper'; 
      wrapper.style.display = 'flex';
      wrapper.style.alignItems = 'center';
      wrapper.style.gap = '5px';
      input.parentNode.insertBefore(wrapper, input);
      wrapper.appendChild(input);

      // 2. Tạo input date ẩn
      const hiddenDateInput = document.createElement('input');
      hiddenDateInput.type = 'date';
      hiddenDateInput.style.cssText = 'position: absolute; opacity: 0; width: 0; height: 0; padding: 0; border: none; pointer-events: none;';
      hiddenDateInput.value = '2001-01-01';
      wrapper.appendChild(hiddenDateInput);

      // 3. Tạo nút bấm chọn ngày
      const dateButton = document.createElement('button');
      dateButton.type = 'button';
      dateButton.innerHTML = '📅'; 
      dateButton.style.cssText = 'cursor: pointer; padding: 8px 12px; border: 1px solid #ccc; border-radius: 4px;background: #059669';
      wrapper.appendChild(dateButton);

      // 4. Mở trình chọn ngày khi nhấn nút
      dateButton.addEventListener('click', () => {
        if (typeof hiddenDateInput.showPicker === 'function') {
          hiddenDateInput.showPicker();
        } else {
          hiddenDateInput.click(); // Fallback cho trình duyệt cũ
        }
      });

      input.addEventListener('click', () => {
        dateButton.click();
      });

      // 5. Cập nhật giá trị
      hiddenDateInput.addEventListener('change', function() {
        if (this.value) {
          const [year, month, day] = this.value.split('-');
          input.value = `${day}/${month}/${year}`;
          input.dispatchEvent(new Event('change', { bubbles: true }));
        }
      });
    });
  };

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', initCustomDatepicker);
  } else {
    initCustomDatepicker();
  }

  document.addEventListener('ajaxComplete', () => {
    setTimeout(initCustomDatepicker, 200);
  });
})();


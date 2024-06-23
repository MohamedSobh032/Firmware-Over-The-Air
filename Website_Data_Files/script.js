const uploadForm = document.getElementById('upload-form');
const hexFile = document.getElementById('hex-file');
const hexList = document.getElementById('hex-list');
const flashButton = document.getElementById('flash-button');
const hexSelect = document.getElementById('hex-select');

let uploadedFileNames = [];
let hexFiles = [];

uploadForm.addEventListener('submit', (e) => {
  e.preventDefault();
  const file = hexFile.files[0];
  if (file == undefined) {
    alert("Please Choose a File First!");
  } else {
    const fileIndex = uploadedFileNames.indexOf(file.name);
    if (fileIndex !== -1) {
      hexFiles[fileIndex] = file;
      const li = hexList.children[fileIndex];
      li.textContent = file.name;
    } else {
      uploadedFileNames.push(file.name);
      hexFiles.push(file);
      const li = document.createElement('li');
      li.textContent = file.name;
      hexList.appendChild(li);
      const option = document.createElement('option');
      option.value = file.name;
      option.textContent = file.name;
      hexSelect.appendChild(option);
    }
  }
});

flashButton.addEventListener('click', () => {
  const selectedOption = hexSelect.options[hexSelect.selectedIndex];
	if (selectedOption.value === '') {
		alert('Please select a hex file first!');
		return;
	} else {
    // Get the selected hex file data
    const selectedHexFile = document.querySelector('#hex-select');
    const hexFileData = hexFiles[selectedHexFile.selectedIndex-1];
    // Send the hex file data to the server
    const reader = new FileReader();
    reader.onload = function(e) {
        const hexData = e.target.result;
        const lines = hexData.split('\n');
        const address1 = lines[0].substring(9, 13);
        const address2 = lines[1].substring(3, 7);
        const fullAddress = address1 + address2;
        const formData = {
          "hexData": hexData,
          "fullAddress": fullAddress
        }
        fetch('script.php', {
          method: 'POST',
          headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
          },
          body: JSON.stringify(formData)
        })
        .then(response => response.text())
        .then(data => {
          alert(data);
        })
        .catch(error => {
          console.error('Error:', error);
          alert('An error occurred while writing the file. Please try again.');
        });
    }
    reader.readAsText(hexFileData);
    }
});
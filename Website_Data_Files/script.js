const uploadForm = document.getElementById('upload-form');
const hexFile = document.getElementById('hex-file');
const hexList = document.getElementById('hex-list');
const flashButton = document.getElementById('flash-button');
const hexSelect = document.getElementById('hex-select');

let uploadedFileNames = [];
let hexFiles = [];

function sendHexData(hexData) {
  const hexDataString = 'hexData=' + hexData;
  fetch('script.php', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded'
    },
    body: hexDataString
  })
  .then(response => response.text())
  .then(data => {
    console.log(data);
    alert(data);
  })
  .catch(error => {
    console.error('Error:', error);
    alert('An error occurred while writing the file. Please try again.');
  });
}

function checkIfFileAlreadyUploaded(fileName) {
  return uploadedFileNames.includes(fileName);
}

uploadForm.addEventListener('submit', (e) => {
  e.preventDefault();
  const file = hexFile.files[0];
  if (file == undefined) {
    alert("Please Choose a File First!");
  } else {
    const fileName = file.name;
    if (checkIfFileAlreadyUploaded(fileName)) {
      alert("File with the same name already uploaded!");
    } else {
      uploadedFileNames.push(fileName);
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
        sendHexData(hexData);
    }
    reader.readAsText(hexFileData);
    }
});
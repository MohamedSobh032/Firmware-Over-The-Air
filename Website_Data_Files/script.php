<?php
$dataToWrite = $_POST['hexData'];
$filename = 'file.txt';
if (file_put_contents($filename, $dataToWrite)) {
    file_put_contents('ReadorNotFile.txt', 'N');
    echo "Project has been Uploaded Successfully. Please Reset your MCU";
} else {
    echo "An error occurred while writing the file. Please try again!";
}

<?php
if (isset($_POST)) {
    $Received = json_decode(file_get_contents("php://input"), true);
    $dataToWrite = $Received["hexData"];
    $fullAddress = $Received["fullAddress"];
    if (file_put_contents('file.txt', $dataToWrite)) {
        $settingsData = 'N ' . $fullAddress;
        if (file_put_contents('FileSettings.txt', $settingsData) !== false) {
            echo "Project has been Uploaded Successfully. Please Reset your MCU";
        } else {
            echo "An error occurred while writing FileSettings.txt. Please try again!";
        }
    } else {
        echo "An error occurred while writing the file.txt. Please try again!";
    }
}

if (isset($_GET['line'])) {
    $hexdata = file('file.txt');
    $output = $hexdata[$_GET['line']] . $hexdata[$_GET['line']+1];
    echo $output;
}

if (isset($_GET['end'])) {
    file_put_contents('FileSettings.txt', 'O');
}
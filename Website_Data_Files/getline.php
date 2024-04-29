<?php
if (isset($_GET['line'])) {
    $hexdata = file('file.txt');
    $output = $hexdata[$_GET['line']] . $hexdata[$_GET['line']+1];
    echo $output;
}
if (isset($_GET['end'])) {
    file_put_contents('ReadorNotFile.txt', 'O');
}
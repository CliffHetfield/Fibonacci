chcp 65001 >nul
powershell -Command "'' | Out-File -FilePath results.txt -Encoding utf8"

powershell -Command "Add-Content results.txt 'TEST1: Только цифры и пробелы (0 1 1 2 3 5 8 13)'"
if exist output01.txt del output01.txt
FibonacciNumbers.exe test01.txt output01.txt
powershell -Command "Get-Content output01.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST2: Только некорректные символы (abc !@)'"
if exist output02.txt del output02.txt
FibonacciNumbers.exe test02.txt output02.txt
powershell -Command "Get-Content output02.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST3: Цифры, пробелы и некорректные символы (0 1 1 2a 3 5)'"
if exist output03.txt del output03.txt
FibonacciNumbers.exe test03.txt output03.txt
powershell -Command "Get-Content output03.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST4: Одна корректная строка, последовательность Фибоначчи (0 1 1 2 3 5 8)'"
if exist output04.txt del output04.txt
FibonacciNumbers.exe test04.txt output04.txt
powershell -Command "Get-Content output04.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST5: Одна корректная строка, не Фибоначчи (0 1 2 4 7)'"
if exist output05.txt del output05.txt
FibonacciNumbers.exe test05.txt output05.txt
powershell -Command "Get-Content output05.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST6: Пустая строка'"
if exist output06.txt del output06.txt
FibonacciNumbers.exe test06.txt output06.txt
powershell -Command "Get-Content output06.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST7: Две строки, обе Фибоначчи'"
if exist output07.txt del output07.txt
FibonacciNumbers.exe test07.txt output07.txt
powershell -Command "Get-Content output07.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST8: Две строки, обе не Фибоначчи'"
if exist output08.txt del output08.txt
FibonacciNumbers.exe test08.txt output08.txt
powershell -Command "Get-Content output08.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST9: Одна некорректная строка'"
if exist output09.txt del output09.txt
FibonacciNumbers.exe test09.txt output09.txt
powershell -Command "Get-Content output09.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST10: Отрицательные числа'"
if exist output10.txt del output10.txt
FibonacciNumbers.exe test10.txt output10.txt
powershell -Command "Get-Content output10.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST11: Одна цифра (0)'"
if exist output11.txt del output11.txt
FibonacciNumbers.exe test11.txt output11.txt
powershell -Command "Get-Content output11.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST12: 1001 число'"
if exist output12.txt del output12.txt
FibonacciNumbers.exe test12.txt output12.txt
powershell -Command "Get-Content output12.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST13: Минимальная последовательность Фибоначчи (0 1)'"
if exist output13.txt del output13.txt
FibonacciNumbers.exe test13.txt output13.txt
powershell -Command "Get-Content output13.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST14: Последовательность Фибоначчи из 5 чисел (0 1 1 2 3)'"
if exist output14.txt del output14.txt
FibonacciNumbers.exe test14.txt output14.txt
powershell -Command "Get-Content output14.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST15: Последовательность Фибоначчи из 20 чисел'"
if exist output15.txt del output15.txt
FibonacciNumbers.exe test15.txt output15.txt
powershell -Command "Get-Content output15.txt | Add-Content results.txt"

powershell -Command "Add-Content results.txt 'TEST16: Минимальная строка, не содержащая последовательность Фибоначчи (1)'"
if exist output16.txt del output16.txt
FibonacciNumbers.exe test16.txt output16.txt
powershell -Command "Get-Content output16.txt | Add-Content results.txt"


# Shellcode Runner in C with RC4 Encryption
Two C programs. One encrypts shellcode via RC4. The other decrypts the RC4-encrypted shellcode at runtime and executes it.

## How to use
1. Add unencrypted shellcode to source file encrypt_shellcode.c and modify rc4 password if desired
2. Build source file with `cl encrypt_shellcode.c` and run `encrypt_shellcode.exe`
3. Copy output from encrypt_shellcode.exe and copy into source file `execute_encrypted_shellcode.c`
4. Build source file with `cl execute_encrypted_shellcode.c` and run `execute_encrypted_shellcode.exe`

## References
1. [Red Teaming 101: Executing Malicious Shellcode with C — a guide for beginners](https://medium.com/@lsecqt/red-teaming-101-executing-malicious-shellcode-with-c-a-guide-for-beginners-439bff63721d)
2. [A Beginner's Guide to Windows Shellcode Execution Techniques](https://csandker.io/2019/07/24/ABeginnersGuideToWindowsShellcodeExecutionTechniques.html#function-pointer-execution)

// #include "shell.h"
// // pid_t to typ danych do zarządzania procesami
// // fork() tworzy proces dziecko
// // jeśli child process jest -1 to error, jeśli child process == 0 to super i wywołamy ten proces
// void    execute_command(const char *command)
// {
//     pid_t child_pid = fork();

//     if(child_pid == -1)
//     {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     } else if(child_pid == 0) {
//         execlp(command, command, (char *)NULL); // t musi byc zamienione na execve
//         perror("execlp");
//         exit(EXIT_FAILURE);
//     }
//     else 
//     {
//         //Parent process
//         wait(NULL);
//     }
// }
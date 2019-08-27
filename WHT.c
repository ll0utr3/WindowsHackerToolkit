#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
int WHT = 0;

int logs(void){
  if (WHT == 1){
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
  }
  printf("[!] Deleting all Windows logs...\n");
  system("(for /f \%x in ('wevtutil el') do wevtutil cl \"%x\") >nul 2>&1");
  printf(GREEN "[+] Successfully deleted all logs !\n" RESET);
}

int defenderoff(void){
  if (WHT == 1){
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
  }
  printf("[!] Disabling Windows Defender...\n");
  system("powershell Set-MpPreference -DisableRealtimeMonitoring $true >nul 2>&1");
  printf(GREEN "[+] Successfully disabled Windows Defender !\n" RESET);
}

int firewalloff(void){
  if (WHT == 1){
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
  }
  printf("[!] Disabling Windows Firewall...\n");
  system("netsh advfirewall set privateprofile state off >nul 2>&1");
  system("netsh advfirewall set domainprofile state off >nul 2>&1");
  system("netsh advfirewall set publicprofile state off >nul 2>&1");
  printf(GREEN "[+] Successfully disabled Windows Firewall !\n" RESET);
}

int defenderon(void){
  if (WHT == 1){
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
  }
  printf("[!] Enabling Windows Defender...\n");
  system("powershell Set-MpPreference -DisableRealtimeMonitoring $false >nul 2>&1");
  printf(GREEN "[+] Successfully enabled Windows Defender !\n" RESET);
}

int firewallon(void){
  if (WHT == 1){
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
  }
  printf("[!] Enabling Windows Firewall...\n");
  system("netsh advfirewall set privateprofile state on >nul 2>&1");
  system("netsh advfirewall set domainprofile state on >nul 2>&1");
  system("netsh advfirewall set publicprofile state on >nul 2>&1");
  printf(GREEN "[+] Successfully enabled Windows Firewall !\n" RESET);
}

int main (int argc, char **argv){
  if (argc == 1){
    int choix;
    printf("[!] Welcome on Windows Hacker Toolkit ! (this program will only work if you launch as an admin !)\n");
    printf("[1] Delete all Windows logs\n");
    printf("[2] Disable Windows Defender\n");
    printf("[3] Disable Windows Firewall\n");
    printf("[4] Enable Windows Defender\n");
    printf("[5] Enable Windows Firewall\n");
    printf("[*]>> ");
    scanf("%d", &choix);
    if (choix == 1){
      logs();
    }
    else if (choix == 2){
      defenderoff();
    }
    else if (choix == 3){
      firewalloff();
    }
    else if (choix == 4){
      defenderon();
    }
    else if (choix == 5){
      firewallon();
    }
  }
  else if (stricmp ("logs",argv[1]) == 0 || stricmp ("clear_logs",argv[1]) == 0){
    WHT = 1;
    logs();
  }
  else if (stricmp ("defenderon",argv[1]) == 0 || stricmp ("defender_on",argv[1]) == 0){
    WHT = 1;
    defenderon();
  }
  else if (stricmp ("defenderoff",argv[1]) == 0 || stricmp ("defender_off",argv[1]) == 0){
    WHT = 1;
    defenderoff();
  }
  else if (stricmp ("firewallon",argv[1]) == 0 || stricmp ("firewall_on",argv[1]) == 0){
    WHT = 1;
    firewallon();
  }
  else if (stricmp ("firewalloff",argv[1]) == 0 || stricmp ("firewall_off",argv[1]) == 0){
    WHT = 1;
    firewalloff();
  }
  return 0;
}

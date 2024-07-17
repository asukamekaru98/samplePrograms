#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void extract_info(const char* input)
{
    const char* start = input;
    const char* end;
    int i = 0;
    char deviceCnt;
    char address[9][13];  // Bluetoothアドレスは12文字 + null終端
    char name[9][50];     // Bluetooth名の最大長を50と仮定
    //int i;

    if (strncmp(start, "Inquiry Done", 12) == 0) {
        return;
    }

//    if ((pFount = strstr((char*)sBTDeviceList, "Found ")) == NULL) return;
//    deviceCnt = Str2Int(pFount + 6);

    while ((start = strstr(start, "\r\n")) != NULL) {
        start += 3;  // "\r\n"の後に進める

    //    if (strncmp(start, "Inquiry Done", 12) == 0) {
    //        break;
    //    }

        // Bluetooth アドレスを抽出
        end = strchr(start, ',');
        if (end == NULL) {
            break;
        }
        strncpy(address[i], start, end - start);
        address[i][end - start] = '\0';

        // Bluetooth 名を抽出
        start = end + 1;
        end = strchr(start, ',');
        if (end == NULL) {
            break;
        }
        strncpy(name[i], start, end - start);
        name[i][end - start] = '\0';

        // 結果を出力
        printf("Bluetooth Address: %s, Bluetooth Name: %s\n", address[i], name[i]);
    }
}

int main()
{
    const char* input = "Inquiry,T=8,COD=0\x0d\x0a 0C938F06EBB4,OPPO Reno3 A,5A020C\x0d\x0a 402343E6B7F6,LAPTOP-ITOU,2A010C\x0d\x0a A0510B37447E,S_SAKURAI10,2A010C\x0d\x0a Found 3\x0d\x0a Inquiry Done\x0d\x0a CMD> \0";

    extract_info(input);

    return 0;
}

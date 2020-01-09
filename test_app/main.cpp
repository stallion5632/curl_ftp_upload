#include "curl_ftp_upload.h"
#include <stdio.h>
int main(void)
{
    char remotepath[] = "aa/MicrosoftOffice2016.zip";
    char localpath[] = "C:/test/MicrosoftOffice2016.zip";

    int ret = init("10.40.27.82", "admin", "iflytek");
    if (ret == 0)
    {
        ret = upload_file2(remotepath, localpath, 0, 3, 1);
    }
    
    getchar();
    cleanup();
    return 0;
}

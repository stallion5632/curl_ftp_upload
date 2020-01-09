
# ref: https://www.cnblogs.com/ccxikka/p/9637545.html
from cffi import FFI
ffi = FFI()

ffi.cdef("""
    int init(const char* ip, const char* username, const char* passwd);
    void cleanup();
    void upload_file(const char *remotepath, const char *localpath);
    void upload_file2(const char *remotepath, const char *localpath, int timeout, int tries, int overlap);
""")

lib = ffi.dlopen('curl_ftp_upload.dll') 
ip = ffi.new("char[]", b"10.40.27.82") 
username = ffi.new("char[]", b"admin") 
passwd = ffi.new("char[]", b"iflytek") 
remotepath = ffi.new("char[]", b"aa/MicrosoftOffice2016.zip") 
localpath = ffi.new("char[]", b"C:/test/MicrosoftOffice2016.zip") 

###########################
ret = lib.init(ip, username, passwd)
if (ret == 0):
    lib.upload_file(remotepath, localpath)
else:
    print('init failed')

Q = input("Enter q to quit the pro!")
if Q.lower() == 'q':
    exit(0)
    
lib.cleanup();
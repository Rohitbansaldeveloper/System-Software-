
#===============================================================================================================================================
 # Name: 01_shell
 # Roll Number: MT2025105
 # Date : 27 Aug 2025

# ================================================================================================================================================
# 1.a Soft link (symlink system call)
ln -s source.txt softLink.txt

# 1.b Hard link (link system call) 
ln source.txt hardLink.txt

# 1.c FIFO (mkfifo Library Function or mknod system call)
mkfifo fifo

echo "Creating soft link..."
echo "Testing soft link creation." > src_file_soft_link.txt
ln -s src_file_soft_link.txt soft_link.txt
echo "Soft link: soft_link.txt -> src_file_soft_link.txt"
ls -l
echo "#########################################"
echo "Creating hard link..."
echo "Testing hard link creation." > src_file_hard_link.txt
ln src_file_hard_link.txt hard_link.txt
echo "Hard link: hard_link.txt -> src_file_hard_link.txt"
ls -l
echo "#########################################"
./ft_mini_ls $1 &
sleep 1
leaks $! | grep -E ' leaks?'
kill $!
while true; do
./gen.out >in
./a.out <in >o
./b.out <in > o1
if diff o o1; then
    printf AC
else 
    echo WA
    exit 0
fi
done

def init
  $n = gets.to_i
  $a = gets.split(' ').map(&:to_i)
end

init

$a.sort!.reverse!
alice = 0
bob = 0
$a.each_with_index {|v, i| i % 2 == 0 ? alice += v : bob += v}
p alice - bob

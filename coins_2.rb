# https://atcoder.jp/contests/abs/submissions/6855359
def init
  $num_a = gets.chomp.to_i
  $num_b = gets.chomp.to_i
  $num_c = gets.chomp.to_i
  $x = gets.chomp.to_i
end

init

def puts_and_exit
  puts 0
  exit
end

puts_and_exit if $x > $num_a * 500 + $num_b * 100 + $num_c * 50

ax = [$num_a, $x.div(500)].min
bx = [$num_b, ($x - ax * 500).div(100)].min
cx = [$num_c, ($x - ax * 500 - bx * 100).div(50)].min
puts_and_exit if $x != ax * 500 + bx * 100 + cx * 50

answer = 0
(ax + 1).times do |i|
  bx_reduced_from_a = bx + i * 5

  (bx_reduced_from_a + 1).times do |j|
    bx_reduced_to_c = bx_reduced_from_a - j
    cx_reduced_from_b = cx + j * 2

    answer += 1 if bx_reduced_to_c <= $num_b && cx_reduced_from_b <= $num_c
  end
end

puts answer

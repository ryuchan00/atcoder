# https://atcoder.jp/contests/abc073/tasks/abc073_b


N = gets.to_i
ls = Array.new(N)
rs = Array.new(N)
N.times do |i|
  ls[i], rs[i] = gets.split.map(&:to_i)
end

puts ans

# https://atcoder.jp/contests/abc065/tasks/arc076_b


N = gets.to_i
xs = Array.new(N)
ys = Array.new(N)
N.times do |i|
  xs[i], ys[i] = gets.split.map(&:to_i)
end

puts ans

# https://atcoder.jp/contests/abc092/tasks/abc092_b


N = gets.to_i
D, X = gets.split.map(&:to_i)
As = Array.new(N) { gets.to_i }
sum = X

N.times do |i|
  sum += (D.to_f / As[i]).ceil
end

puts sum

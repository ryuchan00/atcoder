N, K = gets.split.map(&:to_i)
hs = gets.split.map(&:to_i)

puts hs.select { |h| h >= K }.size

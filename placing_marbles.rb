a = gets.chomp.split("").map(&:to_i)
count = 0
a.each do |num|
  count+=1 unless num.zero?
end
puts count
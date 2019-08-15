def init
  $n, $a, $b = gets.chomp.split(" ").map(&:to_i)
end

init

sum = 0
0.upto($n) do |i|
  work_sum = 0
  i.to_s.size.times do |j|
    work_sum += i.to_s[j].to_i
  end
  sum += i if $b >= work_sum && work_sum >= $a
end
p sum
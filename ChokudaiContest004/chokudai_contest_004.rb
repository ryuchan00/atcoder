n, b1, b2, b3 = gets.split.map(&:to_i)
l = %w()
r = %w()
a = %w()
%w(l r).each do |v|
  n.times do
    eval("#{v}.push(gets.split.map(&:to_i))")
  end
end
line = Array.new(n).fill(0)
n.times { a.push(line) }

l.each_with_index do |row, i|
  sum = 0
  row.each_with_index do |num, j|
    while sum < b3
    [num..r[i][j]]
    p sum
  end
end
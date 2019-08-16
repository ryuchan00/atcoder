def init
  $n = $stdin.gets.chomp.to_i
  # $line = $stdin.read.split("\r\n").map(&:to_i)
  $line = %w()
  while line = gets
    $line.push(line.chomp.to_i)
  end
end

init

$line.sort!.reverse!
count = 1
old = nil
$line.each {|i| old = i and next if old.nil?; count += 1 if old > i;old = i}
puts count
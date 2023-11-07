#!/bin/bash

problem_dir=$1 # relative directory path (${service_name}/${contest_id}/${problem_id})

service_name=${problem_dir%%/*}
contest_id=$(basename ${problem_dir%/*})
problem_id=${problem_dir##*/}

test_dir=${problem_dir}/test

case "$service_name" in
"AtCoder")
  problem_url="https://atcoder.jp/contests/${contest_id}/tasks/${problem_id}"
  ;;
"Codeforces")
  problem_url="https://codeforces.com/contest/${contest_id}/problem/${problem_id}"
  ;;
esac

if [ ! -e ${test_dir} ]; then
  pipenv run oj d -d ${test_dir} ${problem_url}
fi

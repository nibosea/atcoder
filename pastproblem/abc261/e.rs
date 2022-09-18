use itertools::Itertools;
use proconio::input;

fn main() {
	input! {
		n: usize,
		mut c : usize,
		queries : [(u8, usize); n]
	}
	const BIT : usize = 30;

	let mut ans = vec![0; n];
	let mut zero = 0;
	let mut one = std::usize::MAX;
	for (i, &(t,x)) in queries.iter().enumerate() {
		match t {
			1 => {
				zero &= x;
				one &= x;
			}
			2 => {
				zero |= x;
				one |= x;
			}
			3 => {
				zero ^= x;
				one ^= x;
			}
			_ => unreachable!()
		}
		ans[i] = (c & one) | (!c & zero);
		c = ans[i];
	}
	println!("{}", ans.iter().join("\n"));
}

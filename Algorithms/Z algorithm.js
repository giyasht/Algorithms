/*
    This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m, 
    then total time taken is O(m + n) with linear space complexity. 
    Now we can see that both time and space complexity is same as KMP algorithm but this algorithm is Simpler to understand.
    In this algorithm, we construct a Z array.
*/
// A JavaScript program that implements Z algorithm for pattern
// searching

// prints all occurrences of pattern in text using
	// Z algo
function search(text,pattern)
{
	// Create concatenated string "P$T"
		let concat = pattern + "$" + text;

		let l = concat.length;

		let Z = new Array(l);

		// Construct Z array
		getZarr(concat, Z);

		// now looping through Z array for matching condition
		for(let i = 0; i < l; ++i){

			// if Z[i] (matched region) is equal to pattern
			// length we got the pattern

			if(Z[i] == pattern.length){
				document.write("Pattern found at index "
							+ (i - pattern.length - 1)+"<br>");
			}
		}
}

// Fills Z array for given string str[]
function getZarr(str,Z)
{
	let n = str.length;
		
		// [L,R] make a window which matches with
		// prefix of s
		let L = 0, R = 0;

		for(let i = 1; i < n; ++i) {

			// if i>R nothing matches so we will calculate.
			// Z[i] using naive way.
			if(i > R){

				L = R = i;

				// R-L = 0 in starting, so it will start
				// checking from 0'th index. For example,
				// for "ababab" and i = 1, the value of R
				// remains 0 and Z[i] becomes 0. For string
				// "aaaaaa" and i = 1, Z[i] and R become 5

				while(R < n && str[R - L] == str[R])
					R++;
				
				Z[i] = R - L;
				R--;

			}
			else{

				// k = i-L so k corresponds to number which
				// matches in [L,R] interval.
				let k = i - L;

				// if Z[k] is less than remaining interval
				// then Z[i] will be equal to Z[k].
				// For example, str = "ababab", i = 3, R = 5
				// and L = 2
				if(Z[k] < R - i + 1)
					Z[i] = Z[k];

				// For example str = "aaaaaa" and i = 2, R is 5,
				// L is 0
				else{


				// else start from R and check manually
					L = i;
					while(R < n && str[R - L] == str[R])
						R++;
					
					Z[i] = R - L;
					R--;
				}
			}
		}
}

// Driver program
let text = "HELLO HACKTOBER FEST";
let pattern = "HACKTOBER";

search(text, pattern);

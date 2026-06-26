// ================= BUCKET ARRAY =================
// Bucket Array is an array where each index (bucket)
// stores data having the same hash value.\
//Its visualisation are like:
// index-> key elem -> value


// ================= HASH CODE =================
// Hash Code is an integer generated from a key.
// It is used to decide where the value should be stored.
// Example:
// Key = "abc"
// Hash Code = 96354

// ================= COMPRESSION FUNCTION =================
// Converts a large hash code into a valid bucket index.

// Formula:
// bucketIndex = hashCode % bucketSize
//
// Example:
// hashCode = 96354
// bucketSize = 10
// bucketIndex = 4

// ================= COLLISION =================
// Collision occurs when two different keys
// get mapped to the same bucket index.
//
// Example:
// hash("abc") % 10 = 4
// hash("xyz") % 10 = 4
//
// Collision Handling:
// 1. Separate Chaining
// 2. Open Addressing (Linear, Quadratic, Double Hashing)

// ================= COLLISION HANDLINg =================
// 1.Open hashing
// 2.Closed addressing

// ================= Open hashing =================
//In that block a linked list is made
//In our upper example we had abc and xyz both have same hash code -> 4
//process is like first come 'abc' it store in head aand thge 'xyz' it store in next of head
// Aka separate chaining

// ================= Closed addressing =================
// In this like first 'abc' came it stored in our 4th index
//Now 'xyz' came its also have hash code 4 but it is occupied now we move ahead and find empty index index and that is decided by a func
//Eqn: Hi(a) = h(a) + fi(a)
//i -> no of try
//our result is depend on fi(a)

//It type are :
//1. Linear Probing:
//In this fi(a) = i
//Ex: our "abc" is stored on 4th and now "xyz" its hash code also 4 and 4th is occupied

//0Th attempt
//h0(xyz) = h(xyz) + f0(a)
//h0(xyz) = 4 + 0 --> h(a) mean first hash code of xyz
//h0(xyz) = 4 -> meaning xyz will store on 4th index and it is occuped

//1st Attempt
//h1(xyz) = h(xyz) + f1(a)
//h1(xyz) = 4 + 1
//h1(xyz) = 5 -> meaning xyz will store on 5th index and it is empty now "xyz will place here"

//2. Quadratic Probing:
//In this fi(a) = i^2
//Ex: our "abc" is stored on 4th and now "xyz" its hash code also 4 and 4th is occupied

//0Th attempt
//h0(xyz) = h(xyz) + f0(a)
//h0(xyz) = 4 + 0^2 --> h(a) mean first hash code of xyz
//h0(xyz) = 4 -> meaning xyz will store on 4th index and it is occuped

//1st Attempt
//h1(xyz) = h(xyz) + f1(a)
//h1(xyz) = 4 + 1^2
//h1(xyz) = 5 -> meaning xyz will store on 5th index and it is empty now "xyz will place here"


//Complexity Analysis:

//hash code
//n->len of str
//k->len of each word in str

//TC: O(K)
// if n>>k -> O(1)

// ================= Load Factor =================
// n = Number of elements stored
// m = Size (number of slots) of the hash table
//load factor(a) = n/m
//and we will always ensure that a < 0.7

//If we increase n then we have to increase m the it is called RE-HASHING
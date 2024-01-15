namespace codewars
{
    public class Tests
    {
        [Test]
        public void SampleTest()
        {
            Assert.AreEqual(new int[] { 3, 5 }, Kata.Divisors(15));
        }

        [Test]
        public void SampleTest1()
        {
            Assert.AreEqual(new int[] { 2, 4, 8 }, Kata.Divisors(16));
        }

        [Test]
        public void SampleTest2()
        {
            Assert.AreEqual(new int[] { 11, 23 }, Kata.Divisors(253));
        }

        [Test]
        public void SampleTest3()
        {
            Assert.AreEqual(new int[] { 2, 3, 4, 6, 8, 12 }, Kata.Divisors(24));
        }
    }
}
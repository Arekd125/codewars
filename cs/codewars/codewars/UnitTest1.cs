namespace codewars
{
    public class Tests
    {
        [Test]
        public void Test()
        {
            Assert.AreEqual(25, Paper.Paperwork(5, 5));
            Assert.AreEqual(0, Paper.Paperwork(5, -5));
            Assert.AreEqual(0, Paper.Paperwork(-5, -5));
            Assert.AreEqual(0, Paper.Paperwork(-5, 5));
            Assert.AreEqual(0, Paper.Paperwork(5, 0));
        }
    }
}
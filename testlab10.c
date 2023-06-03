        /// <summary>
        /// This test method verifies that the private method FreezeAccount correctly freezes the account by setting the m_frozen field to true.
        /// </summary>
        [TestMethod]
        public void TestVerifyPrivateFrozen()
        {
            // Invoking the private method "FreezeAccount" on the privateObject instance
            privateObject.Invoke("FreezeAccount");

            // Retrieving the value of the private field "m_frozen" from the privateObject instance
            bool frozen = (bool)privateObject.GetField("m_frozen");

            // Asserting that the value of "frozen" is true, indicating that the account has been frozen successfully
            Assert.AreEqual(true, frozen);
        }


        /// <summary>
        /// This test method verifies that when the account is frozen, 
        /// invoking the Debit method should throw an exception with the message "Account frozen".
        /// </summary>
        [TestMethod]
        public void debit_whenaccountisfrozen_shouldthrowexception()
        {
            // Arrange
            double debitAmount = 4.55;

            // Freeze the account by invoking the private method "FreezeAccount" on the privateObject instance
            privateObject.Invoke("FreezeAccount");

            // Act
            try
            {
                // Attempt to debit the specified amount by invoking the private method "Debit" on the privateObject instance
                privateObject.Invoke("Debit", debitAmount);
            }
            catch (Exception e)
            {
                // Assert
                StringAssert.Contains(e.Message, "Account frozen");
                return;
            }

            // If no exception is thrown, fail the test
            Assert.Fail("No exception was thrown.");
        }

#include "CppUnitTest.h"
#include <functional>
#include "../List/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{
	TEST_CLASS(ListUnitTest)
	{
	public:
		TEST_METHOD(ConstructedListIsEmpty)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0U);
		}
		TEST_METHOD(DeleteListSize0)
		{
			List<int> list;
		}
		TEST_METHOD(DeleteListSize1ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 2);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize2ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 3);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize5ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 6);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(SizeEmpty)
		{
			List<int> list;
			Assert::AreEqual(list.size(), (size_t)0U);
		}
		TEST_METHOD(SizeOneElement)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(list.size(), (size_t)1U);
		}
		TEST_METHOD(SizeTwoElements)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::AreEqual(list.size(), (size_t)2U);
		}
		TEST_METHOD(SizeThreeElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(3);
			list.pushFront(23);
			Assert::AreEqual(list.size(), (size_t)3U);
		}
		TEST_METHOD(SizeTenElements)
		{
			List<int> list;
			list.pushFront(14);
			list.pushFront(31);
			list.pushFront(7);
			list.pushFront(4);
			list.pushFront(11);
			list.pushFront(23);
			list.pushFront(17);
			list.pushFront(38);
			list.pushFront(3);
			list.pushFront(45);
			Assert::AreEqual(list.size(), (size_t)10U);
		}

		TEST_METHOD(pushFrontInto0SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(8);
			Assert::AreEqual(size_t{ 1 }, list.size());
		}
		TEST_METHOD(pushFrontInto0SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(8);
			Assert::AreEqual(size_t{ 1 }, list.size());
			Assert::AreEqual(8, list.popBack());
		}
		TEST_METHOD(pushFrontInto1SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(7);
			Assert::AreEqual(size_t{ 2 }, list.size());
		}
		TEST_METHOD(pushFrontInto1SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(6);
			list.pushFront(2);
			Assert::AreEqual(size_t{ 2 }, list.size());
			Assert::AreEqual(6, list.popBack());
			Assert::AreEqual(2, list.popBack());
		}
		TEST_METHOD(pushFrontInto2SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			list.pushFront(2);
			Assert::AreEqual(size_t{ 3 }, list.size());
		}
		TEST_METHOD(pushFrontInto2SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			list.pushFront(9);
			Assert::AreEqual(size_t{ 3 }, list.size());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(1, list.popBack());
			Assert::AreEqual(9, list.popBack());
		}
		TEST_METHOD(pushFrontInto5SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			list.pushFront(2);
			list.pushFront(7);
			list.pushFront(4);
			list.pushFront(9);
			Assert::AreEqual(size_t{ 6 }, list.size());
		}
		TEST_METHOD(pushFrontInto5SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			list.pushFront(9);
			list.pushFront(4);
			list.pushFront(3);
			list.pushFront(7);
			Assert::AreEqual(size_t{ 6 }, list.size());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(1, list.popBack());
			Assert::AreEqual(9, list.popBack());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(3, list.popBack());
			Assert::AreEqual(7, list.popBack());
		}
		TEST_METHOD(pushBackInto0SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushBack(8);
			Assert::AreEqual(size_t{ 1 }, list.size());
		}
		TEST_METHOD(pushBackInto0SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushBack(8);
			Assert::AreEqual(size_t{ 1 }, list.size());
			Assert::AreEqual(8, list.popBack());
		}
		TEST_METHOD(pushBackInto1SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushBack(7);
			Assert::AreEqual(size_t{ 2 }, list.size());
		}
		TEST_METHOD(pushBackInto1SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(6);
			list.pushBack(2);
			Assert::AreEqual(size_t{ 2 }, list.size());
			Assert::AreEqual(2, list.popBack());
			Assert::AreEqual(6, list.popBack());
		}
		TEST_METHOD(pushBackInto2SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			list.pushBack(2);
			Assert::AreEqual(size_t{ 3 }, list.size());
		}
		TEST_METHOD(pushBackInto2SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			list.pushBack(9);
			Assert::AreEqual(size_t{ 3 }, list.size());
			Assert::AreEqual(9, list.popBack());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(1, list.popBack());
		}
		TEST_METHOD(pushBackInto5SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			list.pushFront(2);
			list.pushFront(7);
			list.pushFront(4);
			list.pushBack(9);
			Assert::AreEqual(size_t{ 6 }, list.size());
		}
		TEST_METHOD(pushBackInto5SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			list.pushFront(9);
			list.pushFront(4);
			list.pushFront(3);
			list.pushBack(7);
			Assert::AreEqual(size_t{ 6 }, list.size());
			Assert::AreEqual(7, list.popBack());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(1, list.popBack());
			Assert::AreEqual(9, list.popBack());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(3, list.popBack());
		}
		TEST_METHOD(popBackFrom0SizeListThrowException)
		{
			List<int> list;
			std::function<void(void)> f = [&list] { list.popBack(); };
			Assert::ExpectException<std::exception>(f);
		}
		TEST_METHOD(popBackFrom1SizeList)
		{
			List<int> list;
			list.pushFront(3);
			Assert::AreEqual(3, list.popBack());
			Assert::AreEqual(size_t{ 0 }, list.size());
		}
		TEST_METHOD(popBackFrom2SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			Assert::AreEqual(3, list.popBack());
			Assert::AreEqual(size_t{ 1 }, list.size());
		}
		TEST_METHOD(popBackFrom2SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(size_t{ 1 }, list.size());
			Assert::AreEqual(1, list.popBack());
		}
		TEST_METHOD(popBackFrom5SizeListThenPopFrontAllElements)
		{
			List<int> list;
			list.pushFront(3);
			list.pushFront(5);
			list.pushFront(2);
			list.pushFront(7);
			list.pushFront(4);
			Assert::AreEqual(3, list.popBack());
			Assert::AreEqual(size_t{ 4 }, list.size());
		}
		TEST_METHOD(popBackFrom5SizeListThenPopBackAllElements)
		{
			List<int> list;
			list.pushFront(4);
			list.pushFront(1);
			list.pushFront(9);
			list.pushFront(4);
			list.pushFront(3);
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(size_t{ 4 }, list.size());
			Assert::AreEqual(1, list.popBack());
			Assert::AreEqual(9, list.popBack());
			Assert::AreEqual(4, list.popBack());
			Assert::AreEqual(3, list.popBack());
		}
		TEST_METHOD(popBackFrom1SizeListThenNoMemeoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			List<std::shared_ptr<int>> list;
			list.pushFront(std::shared_ptr<int>(pointer));
			list.popBack();
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(popBackFrom2SizeListThenNoMemeoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			List<std::shared_ptr<int>> list;
			list.pushFront(std::shared_ptr<int>(pointer));
			list.pushFront(std::shared_ptr<int>(pointer));
			list.popBack();
			Assert::IsTrue(pointer.use_count() == 2);
		}
		TEST_METHOD(popBackFrom5SizeListThenNoMemeoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			List<std::shared_ptr<int>> list;
			list.pushFront(std::shared_ptr<int>(pointer));
			list.pushFront(std::shared_ptr<int>(pointer));
			list.pushFront(std::shared_ptr<int>(pointer));
			list.pushFront(std::shared_ptr<int>(pointer));
			list.pushFront(std::shared_ptr<int>(pointer));
			list.popBack();
			Assert::IsTrue(pointer.use_count() == 5);
		}
	};
}

#include <JsRPC/Serializable.h>
#include <JsRPC/plugins/JSONObjectMapper.h>

class TestObjB : public JsRPC::Serializable
{
public:
	JsRPC::SType<char> a;
	JsRPC::SType<std::string> b;

	TestObjB() : 
		Serializable("TEST", 1234)
	{
		this->serializableMapMember("a", a);
		this->serializableMapMember("b", b);
	}
};

class TestObjA : public JsRPC::Serializable  {
public:
	JsRPC::SType<char> v_char;
	JsRPC::SType<wchar_t> v_wchar;
	JsRPC::SType<int8_t> v_int8;
	JsRPC::SType<uint8_t> v_uint8;
	JsRPC::SType<int16_t> v_int16;
	JsRPC::SType<uint16_t> v_uint16;
	JsRPC::SType<int32_t> v_int32;
	JsRPC::SType<uint32_t> v_uint32;
	JsRPC::SType<int64_t> v_int64;
	JsRPC::SType<uint64_t> v_uint64;
	JsRPC::SType<float> v_float;
	JsRPC::SType<double> v_double;
	JsRPC::SType<std::string> v_string;
	JsRPC::SType<std::string> v_string_n;
	//JsRPC::SType<std::list<std::string> > v_stringlist;
	//JsRPC::SType<std::list<int> > v_intlist;
	JsRPC::SType<std::vector<int> > v_intvector;

	JsRPC::SSerializableType<TestObjB> testb_a;
	JsRPC::SSerializableType< JsCPPUtils::SmartPointer<TestObjB> > testb_b;

	TestObjA() : 
	Serializable("TEST", 101) {
		this->serializableMapMember("v_char", v_char);
		this->serializableMapMember("v_wchar", v_wchar);
		this->serializableMapMember("v_int8", v_int8);
		this->serializableMapMember("v_uint8", v_uint8);
		this->serializableMapMember("v_int16", v_int16);
		this->serializableMapMember("v_uint16", v_uint16);
		this->serializableMapMember("v_int32", v_int32);
		this->serializableMapMember("v_uint32", v_uint32);
		this->serializableMapMember("v_int64", v_int64);
		this->serializableMapMember("v_uint64", v_uint64);
		this->serializableMapMember("v_float", v_float);
		this->serializableMapMember("v_double", v_double);
		this->serializableMapMember("v_string", v_string);
		this->serializableMapMember("v_string_n", v_string_n);
		this->serializableMapMember("testb_a", testb_a);
		this->serializableMapMember("testb_b", testb_b);
		this->serializableMapMember("v_intvector", v_intvector);
	}
};



void main()
{
	TestObjA testObjS;
	TestObjA testObjR;

	std::vector<unsigned char> testpayload;

	(*testObjS.testb_a).a = 'a';
	(*testObjS.testb_a).b = std::basic_string<char>("abcdefg");

	testObjS.v_string = "11234";
	testObjS.v_string_n.setNull();

	(*testObjS.v_intvector).clear();
	(*testObjS.v_intvector).push_back(10);
	(*testObjS.v_intvector).push_back(11);
	(*testObjS.v_intvector).push_back(12);
	(*testObjS.v_intvector).push_back(13);

	testObjS.serialize(testpayload);
	testObjR.deserialize(testpayload);

	std::string json = JsRPC::JSONObjectMapper::serialize(&testObjS);
	printf("JSON : \n%s\n\n", json.c_str());

}

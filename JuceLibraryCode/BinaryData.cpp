/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== Compressor.xml ==================
static const unsigned char temp_binary_data_0[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"\r\n"
"<magic>\r\n"
"  <Styles>\r\n"
"    <Style name=\"default\">\r\n"
"      <Nodes/>\r\n"
"      <Classes>\r\n"
"        <plot-view border=\"2\" background-color=\"black\" border-color=\"silver\" display=\"contents\"/>\r\n"
"        <nomargin margin=\"0\" padding=\"0\" border=\"0\"/>\r\n"
"        <group margin=\"5\" padding=\"5\" border=\"2\" flex-direction=\"column\"/>\r\n"
"      </Classes>\r\n"
"      <Types>\r\n"
"        <Slider border=\"0\" slider-textbox=\"textbox-below\"/>\r\n"
"        <ToggleButton border=\"0\" max-height=\"50\" caption-size=\"0\" text=\"Active\"/>\r\n"
"        <TextButton border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <ComboBox border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <Plot border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"              radius=\"0\"/>\r\n"
"        <XYDragComponent border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"                         radius=\"0\"/>\r\n"
"      </Types>\r\n"
"      <Palettes>\r\n"
"        <default/>\r\n"
"      </Palettes>\r\n"
"    </Style>\r\n"
"  </Styles>\r\n"
"  <View id=\"root\">\r\n"
"    <Slider caption=\"Threshold\" parameter=\"THRESHOLD\"/>\r\n"
"    <Slider caption=\"Ratio\" parameter=\"RATIO\"/>\r\n"
"    <Slider caption=\"Attack\" parameter=\"ATTACK\"/>\r\n"
"    <Slider caption=\"Release\" parameter=\"RELEASE\"/>\r\n"
"    <Slider caption=\"Gain\" parameter=\"GAIN\"/>\r\n"
"  </View>\r\n"
"</magic>\r\n"
"\0";

const char* Compressor_xml = (const char*) temp_binary_data_0;

//================== compressor1.xml ==================
static const unsigned char temp_binary_data_1[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"\r\n"
"<magic>\r\n"
"  <Styles>\r\n"
"    <Style name=\"default\">\r\n"
"      <Nodes/>\r\n"
"      <Classes>\r\n"
"        <plot-view border=\"2\" background-color=\"black\" border-color=\"silver\" display=\"contents\"/>\r\n"
"        <nomargin margin=\"0\" padding=\"0\" border=\"0\"/>\r\n"
"        <group margin=\"5\" padding=\"5\" border=\"2\" flex-direction=\"column\"/>\r\n"
"      </Classes>\r\n"
"      <Types>\r\n"
"        <Slider border=\"0\" slider-textbox=\"textbox-below\"/>\r\n"
"        <ToggleButton border=\"0\" max-height=\"50\" caption-size=\"0\" text=\"Active\"/>\r\n"
"        <TextButton border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <ComboBox border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <Plot border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"              radius=\"0\"/>\r\n"
"        <XYDragComponent border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"                         radius=\"0\"/>\r\n"
"      </Types>\r\n"
"      <Palettes>\r\n"
"        <default/>\r\n"
"      </Palettes>\r\n"
"    </Style>\r\n"
"  </Styles>\r\n"
"  <View id=\"root\" resizable=\"1\" resize-corner=\"1\" width=\"500\" height=\"200\">\r\n"
"    <Slider caption=\"Threshold\" parameter=\"THRESHOLD\" lookAndFeel=\"Skeuomorphic\"\r\n"
"            min-value=\"0\" max-value=\"100\" slider-textbox=\"textbox-above\"\r\n"
"            slider-type=\"linear-vertical\" value=\"0\" flex-align-self=\"stretch\"/>\r\n"
"    <Slider caption=\"Ratio\" parameter=\"RATIO\" lookAndFeel=\"Skeuomorphic\"/>\r\n"
"    <Slider caption=\"Attack\" parameter=\"ATTACK\" lookAndFeel=\"Skeuomorphic\"/>\r\n"
"    <Slider caption=\"Release\" parameter=\"RELEASE\" lookAndFeel=\"Skeuomorphic\"/>\r\n"
"    <Slider caption=\"Gain\" parameter=\"GAIN\" lookAndFeel=\"Skeuomorphic\"/>\r\n"
"  </View>\r\n"
"</magic>\r\n"
"\0";

const char* compressor1_xml = (const char*) temp_binary_data_1;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x6bb289bd:  numBytes = 1294; return Compressor_xml;
        case 0x43788964:  numBytes = 1639; return compressor1_xml;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "Compressor_xml",
    "compressor1_xml"
};

const char* originalFilenames[] =
{
    "Compressor.xml",
    "compressor1.xml"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}

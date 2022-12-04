#include "USB_COM.h"
#include <memory>
#include <vector>
const uint16_t vendor_id = 0xabcd;
const uint16_t product_id_list[1] = {0x1234};
const unsigned char endpoint_1 = 0x81;
const int USB_RX_WORDS_PER_MESSAGE = 20;
void imu_cbf_wrapper(struct libusb_transfer* _transfer);

int main(){
    typedef std::vector<std::shared_ptr<N_Communication::USB_COM_UTC>> Vec_pScom;
    Vec_pScom USB_List;
    //rx only: tx bits 4*n
    for (unsigned short i : product_id_list)
        USB_List.push_back(
                std::make_shared<N_Communication::USB_COM_UTC>(
                        USB_RX_WORDS_PER_MESSAGE,
                        4, N_Communication::Vendor_id_Hex(vendor_id),
                        N_Communication::Product_id_Hex(product_id_list[i]),
                        endpoint_1, 0x00));

    //get the utc data
    const N_Communication::usb_utc_rx_data_t * local_usb_drv =USB_List[0]->get_usb_received_data();
    (void)local_usb_drv;

    //start transmit
    for (auto & Iter : USB_List) //reference here
    {
        Iter->USB_Com_Start_Trans_Asy(imu_cbf_wrapper);
    }

    //if you want to print out data
    USB_List[0]->turn_on_print_data();

    while(true)
    {
        for (auto & Iter : USB_List) //reference here
            libusb_handle_events(Iter->get_usb_ctx());
    }
}

void imu_cbf_wrapper(struct libusb_transfer* _transfer)
{
    auto* temp = reinterpret_cast<N_Communication::USB_COM_UTC*>(_transfer->user_data);
    temp->USB_In_CBF(_transfer);
}

package com.project2.market;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.inject.Inject;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartHttpServletRequest;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.project2.dao.BoardDAO;
import com.project2.domain.BoardVO;
import com.project2.domain.ReplyVO;
import com.project2.service.BoardService;
import com.project2.service.ReplyService;

@Controller
@RequestMapping("/*")
public class BoardController {

	@Inject // find bean object for same name
	private BoardService service; // declare BoardService object

	@Inject // find bean object for same name
	private ReplyService replyService; // declare ReplyService object
	// url mapping

	@RequestMapping(value = "/", method = RequestMethod.GET)
	public String getList(Model model, @RequestParam(value = "num", defaultValue = "1") int num) throws Exception {
		// post number
		int count = service.count();

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number

		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}

		List<BoardVO> list = null;
		list = service.listPage(displayPost, postNum); // post information list
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num

		return "board/list";
	}

	@RequestMapping(value = "/Books", method = RequestMethod.GET)
	public String getListbooks(Model model, @RequestParam(value = "num", defaultValue = "1") int num) throws Exception {
		// post number
		int count = service.countCate("Books");

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number

		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		List<BoardVO> list = null;
		list = service.list("Books", displayPost, postNum); // post information list for category
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num
		return "board/listbooks";
	}

	@RequestMapping(value = "/Accessory", method = RequestMethod.GET)
	public String getListaccessory(Model model, @RequestParam(value = "num", defaultValue = "1") int num)
			throws Exception {
		// post number
		int count = service.countCate("Accessory");

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number
		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		List<BoardVO> list = null;
		list = service.list("Accessory", displayPost, postNum); // post information list for category
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num

		return "board/listaccessory";
	}

	@RequestMapping(value = "/Clothes", method = RequestMethod.GET)
	public String getListclothes(Model model, @RequestParam(value = "num", defaultValue = "1") int num)
			throws Exception {
		// post number
		int count = service.countCate("Clothes");

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number

		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		List<BoardVO> list = null;
		list = service.list("Clothes", displayPost, postNum); // post information list for category
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num
		return "board/listclothes";
	}

	@RequestMapping(value = "/Stationery", method = RequestMethod.GET)
	public String getListstationery(Model model, @RequestParam(value = "num", defaultValue = "1") int num)
			throws Exception {
		// post number
		int count = service.countCate("Stationery");

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number

		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		List<BoardVO> list = null;
		list = service.list("Stationery", displayPost, postNum); // post information list for category
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num
		return "board/liststationery";
	}

	@RequestMapping(value = "/Etc", method = RequestMethod.GET)
	public String getListetc(Model model, @RequestParam(value = "num", defaultValue = "1") int num) throws Exception {
		// post number
		int count = service.countCate("Etc");

		// the number of printing post for one page
		int postNum = 3;

		// paging number
		int pageNum = (int) Math.ceil((double) count / postNum);

		// post number
		int displayPost = (num - 1) * postNum;
		int EndNum = 1; // end of page number

		int StartNum = 4; // start of page number

		if (pageNum - 2 <= num && pageNum >= num && num != 1) { // current page endnum -3 ~ endnum
			EndNum = pageNum;
			StartNum = pageNum - 4;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		if (1 <= num && num <= 3 || pageNum <= 0 || pageNum == 1) { // current page 1 ~ 3
			StartNum = 1;
			EndNum = 5;
		} else {
			StartNum = num - 2;
			EndNum = num + 2;
		}
		List<BoardVO> list = null;
		list = service.list("Etc", displayPost, postNum); // post information list for category
		int CurNum = num; // current page number
		List<Map<String, Object>> fileList = new ArrayList<Map<String, Object>>(); // file information
		for (BoardVO vo : list) {
			int bno = vo.getBno(); // get post number
			Map<String, Object> temp = service.selectFile(bno); // file information for post number
			fileList.add(temp); // add file information
		}
		// model : transfer attribute to view
		model.addAttribute("fileList", fileList); // add attribute filelist
		model.addAttribute("CurNum", CurNum);// add attribute currnet page num
		model.addAttribute("list", list);// add attribute post information list
		model.addAttribute("pageNum", pageNum);// add attribute page num
		model.addAttribute("StartNum", StartNum);// add attribute start num
		model.addAttribute("EndNum", EndNum);// add attribute end num
		return "board/listetc";
	}

	// write post
	@RequestMapping(value = "/write", method = RequestMethod.GET)
	public String getWrite() throws Exception {
		return "board/write"; // board/write.jsp
	}

	@RequestMapping(value = "/write", method = RequestMethod.POST)
	public String postWrite(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception {
		service.write(vo, mhsRequest); // write post and file information to database

		return "redirect:/" + vo.getCategory(); // redirect to category
	}

	// view post
	@RequestMapping(value = "/view", method = RequestMethod.GET)
	public String getView(@RequestParam("bno") int bno, Model model) throws Exception {

		BoardVO vo = service.view(bno); // get post information for post number
		model.addAttribute("view", vo); // put post information

		List<ReplyVO> replyList = replyService.readReply(vo.getBno()); // get comment information list for post number
		model.addAttribute("replyList", replyList); // put comment information list
		int countReply = replyService.countReply(vo.getBno()); // get the number of comment for post number
		model.addAttribute("countReply", countReply); // put count number of comment for post number
		Map<String, Object> file = service.selectFile(bno); // get file information for post number
		model.addAttribute("file", file); // put file information
		return "board/view"; // board/view.jsp
	}

	@RequestMapping(value = "/view", method = RequestMethod.POST)
	public String writeReply(@RequestParam("bno") int bno, ReplyVO vo) throws Exception {

		replyService.writeReply(vo); // write comment
		return "redirect:/view?bno=" + bno; // redirect to this post number
	}

	// modify post
	@RequestMapping(value = "/modify", method = RequestMethod.GET)
	public String getModify(@RequestParam("bno") int bno, Model model) throws Exception {
		BoardVO vo = service.view(bno); // get post information for post number
		model.addAttribute("view", vo); // put post information
		return "board/modify"; // board/modify.jsp
	}

	@RequestMapping(value = "/modify", method = RequestMethod.POST)
	public String postModify(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception {
		int file_no = vo.getBno();

		service.deleteFile(file_no); // delete file information of database for post number
		service.modify(vo, mhsRequest); // modify post information of database

		return "redirect:/" + vo.getCategory(); // redirect to this category 1 page
	}

	// delete post
	@RequestMapping(value = "/delete", method = RequestMethod.GET)
	public String getDelete(@RequestParam("bno") int bno) throws Exception {
		BoardVO vo = service.view(bno); // get post information for post number
		service.delete(bno); // delete post for post number

		return "redirect:/" + vo.getCategory(); // redirect to this category 1 page
	}

	// delete comment information
	@RequestMapping(value = "/replydelete", method = RequestMethod.GET)
	public String getDeletereply(@RequestParam("rno") int rno, @RequestParam("bno") int bno, RedirectAttributes rttr)
			throws Exception {

		ReplyVO vo = replyService.viewReply(rno); // get comment information for comment number
		rttr.addFlashAttribute("vo", vo); // put comment information to redirect post
		replyService.deleteReply(rno); // delete comment for comment number
		return "redirect:/view?bno=" + bno; // redirect to view page of this post number
	}
}